struct User {
    username: String,
    email: String,
    sign_in_count: u64,
    active: bool,
}

// returns User instance with the given email and username
fn _build_user(email_c: String, username_c: String) -> User {
    // I delibirately changed the parameter by adding '_c' as suffix, just to show 'Shorthand struct initialization' with below function
    User {
        email: email_c,
        username: username_c,
        sign_in_count: 1,
        active: true,
    }
}


// you should write 'Shorthand struct initialization' if the function parameters are same as of struct fields
fn build_user(email: String, username: String) -> User {
    User {
        email,
        username,
        active: true,
        sign_in_count: 2,
    }
}

fn print_user_detail(user: &User) {
    println!("email: {}", user.email);
    println!("username: {}", user.username);
    println!("count: {}", user.sign_in_count);
    println!("acitve: {}", user.active);
}

// tuple struct

struct Color(i32, i32, i32);
struct Point(i32, i32, i32);


// It is possible for structs to store references to data owned by something else, but to do so requires the use of 'lifetimes'. We'll see 'lifetimes' later, but lets see a example to check what compiler will tell
struct AnotherUser {
    username: &str,
    email: &str,
    count: u32,
    active: bool,
}

fn main() {
    let u1: User = build_user(String::from("this@that.xyz"), String::from("this"));
    print_user_detail(&u1);


    // creating instances from other instances with struct update

    let _u2: User = User {
        email: String::from("notnewemail@xyz.com"),
        username: String::from("notnewemail"),
        // now say we want other fields same as of 'u1', we can either do
        // acitve: u1.active,  // same for rest of the fields
        // or
        ..u1  // this will give same value of fields from 'u1' for fields of 'u2' you didn't set value of
    };


    let black = Color(0, 0, 0);
    let _origin = Point(0, 0, 0);
    println!("{}", black.1);  // to access fields of tuple struct

    let _u3 = AnotherUser {
        email: "Something@somewhere.com",
        username: "Something",
        count: 10,
        active: false,
    };
}
