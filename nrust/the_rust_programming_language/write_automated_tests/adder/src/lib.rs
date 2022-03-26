#[cfg(test)]
mod tests {
    #[test]
    fn it_works() {
        assert_eq!(2 + 2, 4);
    }


    // Tests fail when something in the test function panics. Each test is run in a new thread, and when the main thread sees that a test thread has died, the test is marked as failed
    #[test]
    fn another_test() {
        panic!("Make this test fail");
    }

    // we give assert! macro an argument that evaluates to a Boolean. If the value is true, assert! does nothing and the test passes. If the value is false, the assert! macro calls the panic!

    use super::Rectangle;

    #[test]
    fn larger_can_hold_smaller() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };
        assert!(larger.can_hold(&smaller));
    }

    #[test]
    fn smaller_cannot_hold_larger() {
        let larger = Rectangle {
            width: 8,
            height: 7,
        };
        let smaller = Rectangle {
            width: 5,
            height: 1,
        };
        //assert!(smaller.can_hold(&larger));
        assert!(!smaller.can_hold(&larger));
    }

    //use super::add_two;

    //#[test]
    //fn it_adds_two() {
        //assert_eq!(4, add_two(2));
    //}

    use super::greeting;

    #[test]
    fn greeting_contains_name() {
        let result = greeting("Carol");
        //assert!(result.contains("Carol"));
        // with custom format value
        assert!(
            result.contains("Carol"),
            "Greeting did not contain name, value was '{}'",
            result
            );
    }

    // using Result<T, E> in Tests
    fn it_works2() -> Result<(), String> {
        if 2 + 2 == 4 {
            Ok(())
        }
        else {
            Err(String::from("two plus two doesn't equals four"))
        }
    }

    // We can't use the #[should_panic] annotation on tests that use 'Result<T, E>', instead, you should return an Err value directly when the test should fail
}

#[derive(Debug)]
struct Rectangle {
    width: u32,
    height: u32,
}

impl Rectangle {
    fn can_hold(&self, other: &Rectangle) -> bool {
        self.width > other.width && self.height > other.height
    }
}

// assert_eq! and assert_ne! also print the two values if the assertion fails, which makes it easier to see why the test failed. These macros print their arguments using debug formatting, which means the values being compared must implement the 'PartialEq' and 'Debug' traits. All the primitive types and most of the standard library types implement these traits. For structs and enums that you define, you'll need to implement 'PartialEq' to assert that values of those types are equal or not. You'll need to implement 'Debug' trait to print the values when the assertion fails. Because both traits are derivable traits, this is usually as straightforward as adding '#[derive(PartialEq, Debug)]' annotation to your struct or enum definition
pub fn add_two(a: i32) -> i32 {
    //a + 2
    a + 3  // bug in code
}

// order of arguments in 'assert macros' doesn't matter in Rust

// adding custom failure messages
// Any arguments specified after the one required argument to 'assert!' or the two requried arguments to 'assert_eq!' and 'assert_ne!' are passed along to the 'format!' macro, so you can pass a format string that contains {} placeholders and values to go in those placeholders

pub fn greeting(name: &str) -> String {
    //format!("Hello {}!", name)
    format!("Hello")  // bug by not passing the name
}
