// with references(Rc<T>) and Box<T>, the borrowing rules' invariants are enforced at compile time. With RefCell<T> , these invariants are enforced at runtime

// The RefCell<T> type is useful when your're sure your code follows the borrowing rules but the compiler is unable to understand and guarantee that

// Because 'RefCell<T>' allows mutable borrows checked at runtime, you can mutate the value inside the 'RefCell<T>' even when the 'RefCell<T>' is immutable
// Mutating the value inside an immutable value is the 'interior mutability pattern'


// A use case for interior mutabitility: Mock Objects

pub trait Messenger {
    fn send(&self, msg: &str);
}

pub struct LimitTracker<'a, T: Messenger> {
    messenger: &'a T,  // lifetime required(cause of use of reference of generic type)
    value: usize,
    max: usize,
}

impl<'a, T> LimitTracker<'a, T> where T: Messenger {
    pub fn new(messenger: &T, max: usize) -> LimitTracker<T> {
        LimitTracker {
            messenger,
            value: 0,
            max
        }
    }

    pub fn set_value(&mut self, value: usize) {
        self.value = value;

        let percentage_of_max = self.value as f64 / self.max as f64;

        if percentage_of_max >= 1.0 {
            self.messenger.send("Error: You are over your quota!");
        } else if percentage_of_max >= 0.90 {
            self.messenger
                .send("Urgent warning: You've used up over 90% of your quota");
        } else if percentage_of_max >= 0.75 {
            self.messenger
                .send("Warnings: You've used up 75% of your quota");
        }
    }
}

#[cfg(test)]
mod tests {
    use super::*;
    use std::cell::RefCell;

    struct MockMessenger {
        sent_messages: RefCell<Vec<String>>,
    }

    impl MockMessenger {
        fn new() -> MockMessenger {
            MockMessenger {
                sent_messages: RefCell::new(vec![])
            }
        }
    }

    impl Messenger for MockMessenger {
        fn send(&self, message: &str) {  // still an immutable borrow of self, which matches the trait definition
            self.sent_messages.borrow_mut()
                .push(String::from(message));
            //let mut x = self.sent_messages.borrow_mut();
            //let mut y = self.sent_messages.borrow();  // now if these two lines are there, it'll give error for already mutable borrow(it'll be runtime error(panic))
            // or
            //let mut z = self.sent_messages.borrow_mut();  // multiple mutable borrow
        }
    }

    #[test]
    fn it_sends_an_over_75_percent_warning_message() {
        let mock_messenger = MockMessenger::new();
        let mut limit_tracker = LimitTracker::new(&mock_messenger, 100);
        limit_tracker.set_value(80);
        assert_eq!(mock_messenger.sent_messages.borrow().len(), 1);
    }
}


// The 'borrow' method returns the smart pointer type 'Ref', and 'borrow_mut' returns the smart pointer type 'RefMut<T>'. Both types implement 'Deref', so we can treat them like regular references
// The RefCell<T> keeps track of how many 'Ref<T>' and 'RefMut<T>' smart pointers are currently active. Every time we call 'borrow', the 'RefCell<T>' increases its count of how many immutable borrows are active(same for mutable borrows on call for borrow_mut)
// Just like the compile-time borrowing rules, 'RefCell<T>' lets us have many immutable borrows or one mutable borrow at any point in time


