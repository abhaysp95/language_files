// to enable multiple ownership, Rust has a type called Rc<T>, which is an abbreviation for 'reference counting'


// Note that Rc<T> is only for use in single-threaded scenarios.


// second iteration

use std::rc::Rc;

enum List {
    Cons(i32, Rc<List>),  // Each cons variant will not hold a value and Rc<T> pointing to a List
    Nil,
}

use crate::List::{Cons, Nil};
fn common_list() {
    let a = Rc::new(Cons(5, Rc::new(Cons(10, Rc::new(Nil)))));
    println!("count after creating a = {}", Rc::strong_count(&a));
    let b = Cons(3, Rc::clone(&a));  // cloning the Rc<List> that a is holding, thereby increasing the number of references from one to two and letting a and b share ownership of the data in that Rc<List>
    println!("count after creating b = {}", Rc::strong_count(&a));
    {
        let c = Cons(4, Rc::clone(&a));  // cloning Rc<List> and increasing the number of references from 2 to 3
        println!("count after creating c = {}", Rc::strong_count(&a));
    }
    println!("count after c goes out of scope = {}", Rc::strong_count(&a));
}
// Everytime we use Rc::clone, the reference count to the data within the Rc<List> will increase, and the data won't be cleaned up unless there are zero references to it
// Rc::clone doesn't make a deep copy of all the data like most types' implementations of 'clone' do, only increments the reference count



// first iteration

//enum List {
    //Cons(i32, Box<List>),
    //Nil,
//}

//use crate::List::{Cons, Nil};

//fn _common_list() {
    //let a = Cons(5, Box::new(Cons(10, Box::new(Nil))));
    //let b = Cons(3, Box::new(a));  // a moved to b
    //let c = Cons(4, Box::new(b));
//}


fn main() {
    common_list();
}
