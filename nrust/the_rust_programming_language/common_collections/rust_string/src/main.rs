fn main() {
    let mut s = String::new();  // new, empty String

    let data = "Initial contents";
    s = data.to_string();  // creates String, containing 'Initial contents'
    // we also have, String::from("<literal here>");

    // we can use '+' operator or the 'format!' macro to concatenate 'String' values

    s.push_str(", bar");  // push_str takes string slice, because we don't necessarily want to take ownership of the parameter
    println!("s is: {}", s);

    let mut s1 = String::from("foo");
    let s2 = "bar";
    s1.push_str(s2);
    println!("s2 is {}", s2);  // if push_str has taken ownership of s2, we wouldn't have been able to use it here


    // the 'push' method takes a single character as a paramter and adds it to the String

    // concatenation with '+' operator
    let s1 = String::from("Hello, ");
    let s2 = String::from(", World!!!");
    // let temp_s3 = &s1 + &s2;  // you can't do this
    let _s3 = s1 + &s2;  // s1 has been moved here and can no longer be used,


    // above '+' has somewhat signature like
    // fn add(self, s: &str) -> String {}
    // but, we can do s1 + &s2, because compiler can coerce &String(which would be type for &s2) to &str(type for 2nd parameter of 'add')
    // when we call the 'add' method, Rust uses 'deref coercion', which here turns &s2 into &s2[..](and this is type of &str)o

    let s1 = String::from("tic");
    let s2 = String::from("tac");
    let s3 = String::from("toe");

    let _tictactoe = s1 + "-" + &s2 + "-" + &s3;  // for more complicated string combinations, use

    let s1 = String::from("tic");  // had to redefine again, because s1 is moved in above line for '_tictactoe'
    let _tictactoe = format!("{}-{}-{}", s1, s2, s3);


    let s1 = String::from("hello");
    // let h = s1[0];  // error


    for c in "नमस्ते".chars() {
        println!("{}", c);
    }

    for c in "नमस्ते".bytes() {
        println!("{}", c);
    }
}
