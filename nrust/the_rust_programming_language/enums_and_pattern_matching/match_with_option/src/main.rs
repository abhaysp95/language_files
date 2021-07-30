fn plus_one(x: Option<i32>) -> Option<i32> {
    match x {
        // matches in rust are exhaustive: we must exhaust every last possibility in order for the code to be valid(like in the case of Option)
        None => None,
        Some(i) => Some(i + 1),
    }
}

fn main() {
    let five = Some(5);  // it's actually Option::Some(5)
    let six = plus_one(five);
    let none: Option<i32> = None;  // it's Option::None, and you have to tell the type of <T> for None to use
    let none_val = plus_one(none);  // or you can just directly pass 'None'


    // _ placeholder
    let some_u8_value = 0u8;
    match some_u8_value {
        1 => println!("One"),
        3 => println!("Three"),
        _ => (),
        // The _ pattern will match any value. () is just the unit value, so nothing will happen in the _ case.
    }
}
