// Having multiple owners of mutable data by combining Rc<T> and RefCell<T>
// If you have an 'Rc<T>' that holds a 'RefCell<T>', you can get a value that can have multiple owners and that you can mutate


#[derive(Debug)]
enum List {
    Cons(Rc<RefCell<i32>>, Rc<List>),
    Nil,
}

use crate::List::{Cons, Nil};
use std::cell::RefCell;
use std::rc::Rc;

fn rc_with_refcell() {
    let value = Rc::new(RefCell::new(5));

    let a = Rc::new(Cons(Rc::clone(&value), Rc::new(Nil)));  // we need to clone value, so both 'a' and 'value' have ownership of the inner '5'
    let b = Cons(Rc::new(RefCell::new(3)), Rc::clone(&a));
    let c = Cons(Rc::new(RefCell::new(4)), Rc::clone(&a));

    *value.borrow_mut() += 10; // automatic dereferencing feature to dereference the 'Rc<T>' to the inner RefCell<T> value. The borrow_mut method returns a RefMut<T> smart pointer, and we use the dereference operator on it to change the inner value
    // it is like *(value.borrow_mut()) = 10,
    // not (*value).borrow_mut() = 10
    // and automatic dereferencing is happening for 'value' first

    println!("a after = {:?}", a);
    println!("b after = {:?}", b);
    println!("c after = {:?}", c);
}

fn main() {
    rc_with_refcell();
}
