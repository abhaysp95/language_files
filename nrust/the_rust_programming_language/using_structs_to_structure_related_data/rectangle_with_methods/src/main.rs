#[derive(Debug)]
struct Rectangle {
    height: u32,
    width: u32,
}

// defining methods
impl Rectangle {
    fn area(&self) -> u32 {  // self paramter tells about information for ownership, borrowing etc. and 'automatic referencing' works for this reason only(because methods have clear reciever(of self))
        self.height * self.width
    }

    fn can_hold(&self, other: &Rectangle) -> bool {
        self.height > other.height && self.width > other.width
    }

// Associated functions
// they doesn't takes 'self' parameter, and are often used for constructors that will return new instance of struct

    fn square(side: u32) -> Rectangle {
        Rectangle {
            height: side,
            width: side,
        }
    }
}

fn main() {
    let r1 = Rectangle {
        height: 10,
        width : 20
    };
    let r2 = Rectangle {
        height: 15,
        width: 18,
    };
    let r3 = Rectangle {
        height: 8,
        ..r2
    };
    println!("r1 is {:#?}", r1);
    println!("r2 is {:#?}", r2);
    println!("r3 is {:#?}", r3);
    println!("area of r1 is {}", r1.area());
    println!("can r1 hold r2: {}", r1.can_hold(&r2));
    println!("can r1 hold r3: {}", r1.can_hold(&r3));

    let sq = Rectangle::square(50);
    println!("sq is {:#?}", sq);
    println!("area of sq is: {}", sq.area());
}
