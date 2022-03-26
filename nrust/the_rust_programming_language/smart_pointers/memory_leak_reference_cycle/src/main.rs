// happening of reference cycle and how to prevent it

use crate::List::{Cons, Nil};
use std::cell::RefCell;
use std::rc::{Rc, Weak};

#[derive(Debug)]
enum List {
    Cons(i32, RefCell<Rc<List>>),  // here we can modify, which 'List' value a 'Cons' variant is pointing to
    Nil,
}

impl List {
    fn tail(&self) -> Option<&RefCell<Rc<List>>> {
        match self {
            Cons(_, item) => Some(item),
            Nil => None,
        }
    }
}




fn reference_cycle_demo() {
    let a = Rc::new(Cons(5, RefCell::new(Rc::new(Nil))));

    println!("a initial rc count = {}", Rc::strong_count(&a));
    println!("a next item = {:?}", a.tail());

    let b = Rc::new(Cons(10, RefCell::new(Rc::clone(&a))));

    println!("a rc count after b creation = {}", Rc::strong_count(&a));
    println!("b initial rc count = {}", Rc::strong_count(&b));
    println!("b next item = {:?}", b.tail());

    if let Some(link) = a.tail() {
        *link.borrow_mut() = Rc::clone(&b);
    }

    println!("b rc count after changing a = {}", Rc::strong_count(&b));
    println!("a rc count after chaning a = {}", Rc::strong_count(&a));


    //println!("a next item = {:?}", a.tail());
}


// preventing reference cycles: turning an Rc<T> into a Weak<T>

// Strong references are how you can share ownership of an Rc<T> instance. Weak references don't express an ownership relationship. They won't cause a reference cycle because any cycle involving some weak references will be broken once the strong reference count values involved is 0

// Because the value that Weak<T> reference might have been dropped, to do anything with the value that a WEak<T> is pointing to, you must make sure taht value still exists. Do this by calling the 'upgrade' method on a 'Weak<T>' instance, which will return an Option<Rc<T>>. Lets see demo

// Creating a Tree data structure: a Node with child nodes

#[derive(Debug)]
struct Node {
    value: i32,
    parent: RefCell<Weak<Node>>,
    children: RefCell<Vec<Rc<Node>>>,  // interior mutability to Vec of 'Rc<Node>'
}

fn atree() {
    let leaf = Rc::new(Node {
        value: 3,
        parent: RefCell::new(Weak::new()),
        children: RefCell::new(vec![]),
    });

    println!("leaf strong = {}, weak = {}",
             Rc::strong_count(&leaf),
             Rc::weak_count(&leaf));

    println!("leaf parent: {:?}", leaf.parent.borrow().upgrade());

    {
        let branch = Rc::new(Node {
            value: 5,
            parent: RefCell::new(Weak::new()),
            children: RefCell::new(vec![Rc::clone(&leaf)]),
        });

        *leaf.parent.borrow_mut() = Rc::downgrade(&branch);

        println!("branch strong = {}, weak = {}",
                 Rc::strong_count(&branch),
                 Rc::weak_count(&leaf));

        println!("leaf strong = {}, weak = {}",
                 Rc::strong_count(&leaf),
                 Rc::weak_count(&leaf));
    }

    println!("leaf parent after update: {:#?}",
             leaf.parent.borrow().upgrade());

    println!("leaf strong = {}, weak = {}",
             Rc::strong_count(&leaf),
             Rc::weak_count(&leaf));
}

fn main() {
    reference_cycle_demo();
    atree();
}

