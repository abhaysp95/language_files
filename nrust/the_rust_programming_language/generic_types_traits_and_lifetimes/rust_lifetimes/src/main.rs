fn main() {
    // main aim of lifetimes is to prevent dangling references
    //let r;
    //{
        //let x = 5;
        //r = &x;
    //}
    //println!("r: {}", r);   // uncomment these 5 lines to test


    let string1 = String::from("abcd");
    let string2 = "xyz";

    let result = longest(string1.as_str(), string2);
    println!("The longest string is {}", result);

    // example for defining lifetime
    // &i32        // a reference
    // &'a i32     // a reference with an explicit lifetime
    // &'a mut i32 // a mutable reference with an explicit lifetime

    let str1 = "this";
    let res;
    {
        let str2 = String::from("that is");
        res = longest(str1, &str2[..]);
        println!("The longest string is {}", res);
    }
    //println!("The longest string is {}", res);  // this will fail, because lifetime for str2 is smaller than str1
}

//fn longest(x: &str, y: &str) -> &str {
fn longest<'a>(x: &'a str, y: &'a str) -> &'a str {
    if x.len() > y.len() { x }
    else { y }
}
// We've told Rust that the lifetime of the reference returned by the 'longest' function is the same as the smaller of the lifetimes


// if we changed the implementation of the 'longest' function to always return the first parameter rather than the longest string slice, we wouldn't specify a lifetime on the 'y' parameter
fn longest2<'a>(x: &'a str, y: &str) -> &'a str { x }


// When returning a reference from a function, the lifetime parameter for the return type needs to match the lifetime parameter for one of the parameters. If the reference returned does not refer to one of the parameters, it must refer to a value created within this function, which would be a dangling reference because the value will go out of scope at the end of the function.
//fn longest3<'a>(x: &str, y: &str) -> &'a str {
fn longest3<'a>(x: &str, y: &str) -> String {
    let result = String::from("really long string");
    result
}

// lifetime annotations in struct definitions

struct ImportantExcerpt<'a> {
    part: &'a str,
}

fn temp1() {
    let novel = String::from("This is some string");
    let first_sentence = novel.split('.').next().expect("Can't split with .");
    let i = ImportantExcerpt {
        part: first_sentence,
    };
}


// we've written a snippet previously something like this
fn first_word(s: &str) -> &str {
    let bytes = s.as_bytes();

    for (i, &item) in bytes.iter().enumerate() {
        if b' ' == item {
            return &s[0..i];
        }
    }
    &s[..]
}
// the reason above function compiles without lifetime annotaions(because, we learnt that every reference has a lifetime and that you need to specify lifetime parameters for functions or structs that use references) is historical. In early version(pre-1.0), this code wouldn't have compiled, it would've been like this
//fn first_word2<'a>(s: &'a str) -> &'a str {}

// After writing a lot of Rust code, the Rust team found that Rust programmers were entering the same lifetime annotations over and over in particular situations

// The patterns programmed into Rust's analysis of references are called 'lifetime elision rules'. These aren't rules for programmers to follow, they're a set of particular cases that the compiler will consider, and if your code fits these cases, you don't need to write the lifetimes explicitly


// lifetimes on function or method parameters are called 'input lifetimes' and lifetimes on return values are called 'output lifetimes'


// three rules for 'lifetime elision' which compiler tries
// 1. each parameter that is a reference gets its own lifetime parameter
// 2. if there is exactly one input lifetime parameter, that lifetime is assigned to all output lifetime parameters
// 3. if there are multiple input lifetime parameters, but one them is '&self' or '&mut self'(which means it is a method), the lifetime of 'self' is assigned to all output lifetime parameters


// lifetime annotations in method definitions
impl<'a> ImportantExcerpt<'a> {
    fn level(&self) -> i32 {  // no explicit lifetime annotation because of 'lifetime elision first rule'
        3
    }

    // here's an example where third elision rule applies
    fn announce_and_return_part(&self, announcement: &str) -> &str {
        println!("Attention please: {}", announcement);
        self.part
    }
}

// the static lifetime
// "'static" lifetime, which means that this reference can live for the entire duration of the program. All string literals have the "'static" lifetime
fn static_lifetime() {
    let s: &'static str = "I have static lifetime";
}


// generic type parameter, trait bounds and lifetimes together
use std::fmt::Display;

// extra parameter 'ann' of the generic type T, can be filled in by any type that implements the 'Display' trait as specified by the 'where' clause
fn longest_with_an_announcement<'a, T>(
    x: &'a str,
    y: &'a str,
    ann: T
    ) -> &'a str
where T: Display {
    println!("Announcement! {}", ann);
    if x.len() > y.len() { x }
    else { y }
}
