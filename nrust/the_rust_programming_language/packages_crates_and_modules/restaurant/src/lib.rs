mod front_of_house {
    pub mod hosting {
        pub fn add_to_waitlist() {}

        fn seat_at_table() {}
    }

    pub mod serving {
        fn take_order() {}

        pub fn serve_order() {}

        fn take_payment() {}
    }
}

// use crate::front_of_house::hosting;  // using absolute path
// use self::front_of_house::hosting;  // using relative path

use std::collections::HashMap;

// By using 'pub use', external code can now call the 'add_to_waitlist'(or other in that scope)
// function using 'hosting::add_to_waitlist'. If we hadn't specified 'pub use', the
// 'eat_at_restaurant' function could call 'hosting::add_to_waitlist' in its scope, but external
// code couldn't take advantage of this new path
pub use crate::front_of_house::hosting;

pub fn eat_at_restaurant() {  // since, this function is defined in the same module(and level) as 'front_of_house', we don't need to make 'front_of_house' public for this
    // absolute path
    crate::front_of_house::hosting::add_to_waitlist();

    // relative path
    front_of_house::hosting::add_to_waitlist();

    // order a breakfast in summer with Rye toast
    let mut meal = back_of_house::Breakfast::summer("Rye");
    // change our mind about what break we'd like
    meal.toast = String::from("Wheat");
    println!("I'd like {} toast please", meal.toast);

    // meal.seasonal_fruit = String::from("blueberries");  // seasonal_fruit is private field in Breakfast

    let order1 = back_of_house::Appetizer::Soup;
    let order2 = back_of_house::Appetizer::Salad;

    hosting::add_to_waitlist();  // because we bought 'crate::front_of_house::hosting' to scope of eat_at_restaurant by using 'use' keyword

    // Paths bought into scope with 'use' also check privacy, like any other paths

    let mut map = HashMap::new();
    map.insert(1, 2);
}

// The way privacy works in Rust is that all items(functions, methods, structs, enums, modules
// and constants) are private by default. Items in a parent module can't use the private items
// inside the child modules, but items in child modules can use the items in their ancestor
// modules


// starting relative paths with super
fn serve_order() {}

mod back_of_house {
    fn fix_incorrect_order() {
        cook_order();
        super::serve_order();
        // super is just like saying '..' for filesystem path
    }

    fn cook_order() {}

    pub struct Breakfast {  // by putting pub here, we're making struct public, not the fields of struct
        pub toast: String,
        seasonal_fruit: String,
    }

    // this implementation is needed because back_of_house::Breakfast has a private field, the
    // struct needs to provide a public associated function that constructs an instance of
    // Breakfast(we've named 'summer' here). If Breakfast didn't have such function, we couldn't
    // create an instance of Breakfast in eat_at_restaurant because we couldn't set the value of
    // the private seasonal_fruit field in eat_at_restaurant
    impl Breakfast {
        pub fn summer(toast: &str) -> Breakfast {
            Breakfast {
                toast: String::from(toast),
                seasonal_fruit: String::from("peaches"),
            }
        }
    }

    // In contrast of struct, if we make an enum public, all of its variants are then public too
    pub enum Appetizer {
        Soup,
        Salad,
    }
}

use std::fmt::Result;
use std::io::Result as IoResult;

fn func1() -> Result {
    // --snip--
}

fn func2() -> IoResult<()> {
    // --snip--
}


// Nested paths
use std::{cmp::Ordering, io};
use std::io::{self, Write}; // use std::io; and use std::io::Write;

use std::collections::*;  // bring all public items defined in a path into scope, we can specify that path followed by '*', the glob operator
