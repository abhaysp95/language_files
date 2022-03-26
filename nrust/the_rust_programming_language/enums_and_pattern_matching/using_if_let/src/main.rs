fn main() {
    let some_u8_value = Some(0u8);
    match some_u8_value {
        Some(3_u8) => println!("three"),
        None => (),  // even if you covered None, it says that you need to exhaust Some(0_u8..=2_u8) and Some(4_u8..=u8::MAX)
        // so, you will just put '_' placeholder(then you wouldn't have to exhaust 'None' too)
        _ => (),
    }

    // but, we could write this in shorter way, using if let
    let some_u8_value2 = Some(0u8);
    if let Some(3) = some_u8_value2 {
        println!("three");
    }
}
