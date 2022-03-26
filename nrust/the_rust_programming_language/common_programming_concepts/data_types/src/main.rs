use std::io;

fn main() {
    // tuple

    let tup = (500, 6.4, 1);
    let(x, y, z) = tup;
    println!("The value of x, y, z is: {}, {}, {}", x, y, z);

    // or, in addition to destructuring through pattern matching, we can access a tuple element
    // directly using a period(.)
    let x: (i32, f64, u8) = (500, 6.4, 1);
    let _five_hundred = x.0;
    let _six_point_four = x.1;
    let _one = x.2;

    // array
    let a = [1, 2, 3, 4, 5];  // fixed-length, same data type
    // or
    let _a: [i32; 5] = [1, 2, 3, 4, 5];
    // or
    let _a = [3; 5];  // 3, five times
    // or
    let _a: [i32; 10] = [0; 10];

    println!("Please enter an array index.");

    let mut index = String::new();
    io::stdin()
        .read_line(&mut index)
        .expect("Failed to readline");

    let index: usize = index
        .trim()
        .parse()
        .expect("Index entered was not number");

    let element: i32 = a[index];

    println!("The value of the element at index {} is: {}",
             index, element);

    another_function(5, 10);  // function calling

    check_returns();

    println!("Fib of 8 is: {}", fib_number(8));
}

fn another_function(x: i32, _y: i64) {
    println!("Another function, x: {}", x);
}

// statement -> doesn't returns
// expression -> does returns

fn _trail() {
    let _x = 5;
    let y = {
        let x = 3;
        x + 1
    };
    println!("The value of y is: {}", y);

}

// you can return early from a function by using the 'return' keyword(now, I think early thing
// doesn't matter, you can just use 'return' when you want to return) and specifying a value, but
// most functions return the last expression implicitly
fn five() -> i32 {
    5  // don't put ';' here, or else it'll become a statement
}

fn r_five() -> i32 {
    return 5;  // now this is statement, but 'return' is supposed to return
}

fn check_returns() {
    let f1: i32 = five();
    println!("func five() returned: {}", f1);

    let f2: i32 = r_five();
    println!("func r_five() returned: {}", f2);

    println!("7 + 1 = {}", plus_one(7));
}

fn plus_one(x: i32) -> i32 { x + 1 }

// branching
fn _test_if() {
    let number: i32 = 6;

    if 0 == number % 4 {
        println!("number divisible by 4");
    } else if 0 == number % 3 {
        println!("number divisible by 3");
    } else if 0 == number % 2 {
        println!("number divisible by 2");
    } else {
        println!("number not divisible by 4, 3 or 2");
    }
}

fn _if_in_let_statement() {
    let condition: bool = true;
    let number: i32 = if condition { 5 } else { 0 };  // datatype must be same

    println!("The value of number is: {}", number);
}

// code repeatition(looping)
fn _loop_loop() {


    // to return something as result out of loop, put it after 'break'

    let mut counter: i32 = 0;
    let _result = loop {
        counter += 1;
        if 10 == counter {
            break counter * 2;
        }  // no ';' here, because it's an expression(returns something)
    };

    // loops until you explicitly tell it to stop(or something unwanted happens)
    loop { println!("Done here"); }  // if you're gonna call this function, be careful, cause this loop isn't going to break on itself
}

// while loop(conditional loop)
fn _while_loop() {
    let mut number: i32 = 3;
    while 0 != number {
        println!("{}!", number);
        number -= 1;
    }
    println!("LIFTOFF!!!");
}

// for loop
fn _for_loop() {
    let a = [10, 20, 30, 40, 50];

    for element in a.iter() {
        println!("the value is: {}", element);
    }

    for number in (1..4).rev() {
        println!("{}!", number);
    }
    println!("LIFTOFF!!");
}

fn fib_number(num: i32) -> i32 {
    if 1 == num || 0 == num {
        return num;
    }
    fib_number(num - 1) + fib_number(num - 2)
}
