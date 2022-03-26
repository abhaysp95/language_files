#[derive(Debug)]
struct Rectangle {
    height: u32,
    width: u32,
}

fn main() {
    let rect1 = Rectangle {
        height: 10,
        width: 20,
    };
    println!("The area of rectangle is {} sq. pixel", area(&rect1));

    // println!("rect is {}", rect1);  // will not work
    println!("rect is {:#?}", rect1);  // putting ":?" or ":#?" format specifier tells println! to use an output format 'Debug'
    // We do have to enable 'Debug' trait for Rectangle(see top of Rectangle)
}

fn area(rect: &Rectangle) -> u32 { rect.height * rect.width }  // borrowing(not getting ownership)
