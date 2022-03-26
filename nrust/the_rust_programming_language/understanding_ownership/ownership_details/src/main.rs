// In rust, heap memory is freed(or should I say, 'dropped') when the variable containing the pointer for that memory goes out of scope i.e., at '}'.

fn main() {
    let s1 = String::from("Hello, ");  // now this is in heap
    let s2 = s1;
    // structure used
    // in stack, variable s1 which has
    // name -> ptr, len and capacity and will have values for these 3 and ptr will be pointing to the starting memory block at heap(s1 is at stack)
    // s2 will simply copy the thing from s1
    // now one would think that when this function goes out of scope then s1 will be dropped and then will s2 and this will be error like 'double free'(which we get in C/C++), but
    // to ensure memory safety, Rust doesn't considers s1 to be valid anymore and thus it isn't dropped(freed) again when it goes out of scope

    // println!("s1 is: {}", s1); // this will not work anymore
    // So, in C++ terms, s1 was moved to s2(instead of just shallow copy)
    // Rust will never automatically create deep copy of the data


    // if you do want to do perform a deep copy, look at this example below
    let str1 = String::from("World");  // if you'll not use mut, you can't assign anyother thing to str1(like str1 = s2)

    // what happens in this scenrio, is str1 dropped(meaning the heap memory it is pointing is freed ? before taking move(s2)) ?
    //str1 = s2;  // put mut before 'str1' in definition for this line to work
    //println!("str1 is: {}", str1);

    // deep copy
    let str2 = str1.clone();
    println!("str1 is: {}, str2 is: {}", str1, str2);

    o_and_func();

    rv_and_scope();

    first_word_again_mut_tester();
}

// ownership and functions

fn o_and_func() {
    let s = String::from("Random");  // s comes into scope
    takes_ownership(s);  // s's values moves into the function...
    // ... and so is no longer valid here

    // println!("s is: {}", s); // try this

    let x = 5;  // x comes into scope
    makes_copy(x);  // but i32 is Copy(scalar), so it's okay to still use x afterward
} // Here, x goes out of scope, then s(same as like destructors are called in reverse). But because s's value was moved, nothing speciel happens

fn takes_ownership(some_string: String) {  // some_string comes into scope
    println!("Got string: {}", some_string);
}  // here, some_string goes out of scope and 'drop' is called. The backing memory is freed

fn makes_copy(some_int: i32) {  // some_int comes into scope
    println!("Some integer: {}", some_int);
}  // here, some_int goes out of scope. Nothing special happens


// return values and scope
fn rv_and_scope() {
    let s1 = gives_ownership();  // gives_ownership moves its return value into s1

    let s2 = String::from("Again random");  // s2 comes into scope

    let s3 = takes_and_gives_back(s2);  // s2 is moved into takes_and_gives_back, which also moved its return values into s3
}  // here, s3 goes out of scope and is dropped. s2 goes out of scope but was moved already, so nothing happens. s1 goes out of scope and is dropped

fn gives_ownership() -> String{
    let some_string = String::from("hello");
    return some_string;
}

fn takes_and_gives_back(a_string: String) -> String { a_string }


// multiple return(using tuple)
fn _multiple_return() {
    let s1 = String::from("done with random");
    //let (s2, len) = calculate_length(s1);  // updated below
    let len = calculate_length(&s1);
    // let &s1 syntax lets us create a reference that refers to the value of s1 but doesn't own it, the value it points to will not be dropped when the reference goes out of scope

    //println!("The length of '{}' is '{}'", s2, len);  // updated
    println!("The length of '{}' is '{}'", s1, len);
}

//fn calculate_length(s: String) -> (String, usize) {
    //let length: usize = s.len();
    //return (s, length);
//}  // updated function below the below comment

// noticed problem ? Yeah, moving s1 to s in calculate_length() and then moving the same string back as return from calculate_length() to s2

// reference to an object as parameter
fn calculate_length(s: &String) -> usize { s.len() }
// here, above s goes out of scope, but because it doesn't have ownership of what it refers to, nothing happens


// mutable reference
fn _mut_ref() {
    // just as variables are immutable by default, so are references. We're not allowed to modify something we have a reference to
    let mut s = String::from("done");
    change_mut_ref(&mut s);  // passing mutable refernce(making a variable mutable, doesn't makes its reference mutable)
}

fn change_mut_ref(str: &mut String) { str.push_str("!!!"); }


// Restriction with mutable references: you can have only one mutable reference to a particular piece of data in a particular scope
fn _multi_ref_trial() {
    let mut s = String::from("why again!!!");

    let r1 = &mut s;
    //let r2 = &mut s;  // will not work

    //println!("r1: {}, r2: {}", r1, r2);
    println!("r1: {}", r1);
}
// this is to prevent 'data race'

// Data Race(similar to race cond.):
// 1. two or more pointers access the smae data at the same time
// 2. Atleast one of the pointers is being used to write to the data
// 3. There's no mechanism being used to synchronize access to the data
// NOTE: create new scope( '{}' ) to use multiple mutable reference

// We, also can't have mutable reference while we have an immutable one(again, use scope for this problem too)


// NOTE: reference's scope starts from where it is introduced and continuew through the last time that reference is used. so
fn _mut_with_unmut_ref() {
    let mut s = String::from("Why is this happening");

    let r1 = &s; // no problem
    let r2 = &s; // no problem
    println!("r1 and r2: {}, {}", r1, r2);
    // r1 and r2 are no longer used now

    let r3 = &mut s;
    println!("{}", r3);
}


// dangling reference
fn _dang_ref() {
    let _ref_to_nothiing = _dangling_ref();
}

//fn _dangling_ref() -> &String {  // returns a reference to a String
fn _dangling_ref() -> String {  // test the above line(this line is just so that the program compiles(without commenting code))
    let str = String::from("No, just no");
    //return &str;  // you're returning reference to str, not str(which goes out of scope)
    return str;
}


// return word(these are just for the purpose of demonstrating slices and are no way telling the best practice)
fn first_word(str: &String) -> usize {
    let bytes = str.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if b' ' == item { return i; }
    }
    str.len()
}

fn _first_word_tester() {
    let mut s = String::from("Why this again");

    let _word: usize = first_word(&s);

    s.clear();

    // now the _word in itself doesn't have any meaning cause the data _word contain was related to String which was pointed by s and now it is cleared
}

// A string slice is a reference to part of a String

fn _test_string_slice() {
    let str = String::from("Just for testing slice");

    let mut _first = &str[0..4];
    let _second = &str[5..8];

    _first = _second;  // this will work because _first is mutable
}

fn first_word_again(str: &String) -> &str {  // the type that signifies "string slice" is written as &str
    let bytes = str.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if b' ' == item { return &str[..i]; }
    }
    &str[..]
}

fn _first_word_again_tester() {
    let mut s = String::from("Writing this again for testing");
    let word: &str = first_word_again(&s);
    // s.clear();  // can't use because &str is related to it and it's unmutable
    println!("word is: {}", word);
}

fn first_word_again_mut(str: &mut String) -> &mut str {
    let bytes = str.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if b' ' == item {
            return &mut str[..i];
        }
    }
    &mut str[..]
}

fn first_word_again_mut_tester() {
    let mut s = String::from("This will be last time probably");
    let word: &mut str = first_word_again_mut(&mut s);
    // s.clear();  // why is this still wrong ? My guess: it's same to when you do borrowing(by passing the reference as func parameter), so this method is having it behave just like that, probably
    // the question arised because I have mutable reference, but then again, their can exist only one mutable reference for an um..., Object.
    println!("word is: {}", word);
}

// Since, String Literals are string slices, hence they are also immutable(just like its datatype &str is immutable)


fn first_word_last_time(s: &str) -> &str {
    let bytes = s.as_bytes();
    for (i, &item) in bytes.iter().enumerate() {
        if b' ' == item { return &s[..i]; }
    }
    return &s[..]
}

fn _first_word_tester_last_time() {
    let my_string = String::from("Last, I promise!!!");

    // since first_word_last_time() works on slice of string(that is &str)
    let _word = first_word_last_time(&my_string[..]);

    let my_string_redifined = "this is new";
    // you can just pass 'my_string_redifined' as it is as argument(instead of doing &my_string_redifined[..], which you can do by the way), or you can just pass "this is new" as it is(I mean without assigning it to any variable) as argument
    let _new_word = first_word_last_time(my_string_redifined);
}


// there's more general slice type, too

fn _slice_array() {
    let a: [i32; 5] = [1, 2, 3, 4, 5];

    let slice: &[i32] = &a[1..3];  // I'm just explicitly writing the default datatype

    assert_eq!(slice, &[2, 3]);
}
