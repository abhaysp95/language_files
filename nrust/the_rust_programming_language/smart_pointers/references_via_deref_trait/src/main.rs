struct MyBox<T>(T);

impl<T> MyBox<T> {
    fn new(x: T) -> MyBox<T> {
        MyBox(x)
    }
}

// The Deref trait, provided in std. lib, requires us to implement one method named 'deref' that borrows 'self' and returns a reference to the inner data
use std::ops::Deref;

impl<T> Deref for MyBox<T> {
    type Target = T;  // associated type

    fn deref(&self) -> &Self::Target {
        &self.0
    }
}

fn test_mybox() {
    let x = 5;
    let y = MyBox::new(x);

    assert_eq!(5, x);
    assert_eq!(5, *y);  // works because of 'Deref' implementation for 'MyBox'
}


// Without 'Deref' trait, the compiler can only dereference & references


// Implicit defef coercions with functions and methods
// deref coercion is a convinience that Rust performs on arguments to functions and methods. Deref coercion works only on types that implement the 'Deref' trait. Like, deref coercion can convert &String to &str because String implements the 'Deref' trait such that it returns 'str'

fn hello(name: &str) {
    println!("Hello, {}!", name);
}

fn main() {
    println!("Hello, world!");
    test_mybox();
    hello("rust");
    // with deref coercion, wyou can do this
    let m = MyBox::new(String::from("Rust"));
    hello(&m);
    // here we are calling 'hello' with argument '&m', which is a reference to a 'MyBox<String>', because we implemented the Deref trait on MyBox<T>, Rust can turn '&MyBox<String>' to '&String' and std lib implementation of Deref on String that returns String slice, Rust calls deref again to turn the &String to &str, which matches the 'hello' functions definition
    // if rust didn't implement deref coercion, we would have to write the code like this
    hello(&(*m)[..]);
}

// Similar to how the 'Deref' trait is used to override the * operator on immutable references, you can use the 'DerefMut' trait to override the * operator on mutable references

// Rust does deref coercion when it finds types and trait implementations in three cases:
// 1. From &T to &U when T: Deref<Target=U>
// 2. From &mut T to &mut U when T: DerefMut<Target=U>
// 3. From &mut T to &U when T: Deref<Target=U>
