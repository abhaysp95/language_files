// you'll mostly use Boxes when

// 1. when you have a type whose size can't be known at compile time and you wnat to use a value of that type in a context that requires an exact size
// 2. When you have a large amount of data and you want to transfer ownership bt ensure the data won't be copied when you do so
// 3. When you want to own a value and you care only that it's a type that implements a particular trait rather than being of a specific type

// Box is type of smart pointer(like String and Vec<T>). Smart Pointer implement two traits: 'Deref' and 'Drop'

// Using a Box<T> to store Data on the heap
fn _box_usage() { // not much useful(just demonstrating Box)
    let b = Box::new(5);
    println!("b = {}", b);
}

// Enabling Recursive types with Boxes
// let's explore 'cons list', which is a data type common in functional programming languages, as an example of a recursive type

// In Lisp(from where 'cons' fn came), the 'cons function'(short for "construct function") constructs a new pair from its two arguments, which usually are single value and another pair. These pairs containing pairs form a list

// The cons function concept has made its way into more general functional programming jargon: "to cons x onto y" informally means to construct a new container instance by putting the element x at the start of this new container followed by the container y

//enum List {
    //Cons(i32, List),  // Rust can't figure out how much space is needed for this recursively defined type('List') here
    //Nil
//}
// Because, 'Box<T>' is a pointer, Rust always knows how much space a 'Box<T>' needs: a pointer's size doesn't change based on the amount of data it's pointing to. This means we can put 'Box<T> inside the 'Cons' variant instead of another 'List' value directly
enum List {
    Cons(i32, Box<List>),  // it isn't necessary to name it 'Cons'
    Nil,
}

use crate::List::{Cons, Nil};

fn rename_later() {
    let list = Cons(1, Box::new(Cons(2, Box::new(Cons(3, Box::new(Nil))))));
}

fn main() {
    println!("Hello, world!");
}
