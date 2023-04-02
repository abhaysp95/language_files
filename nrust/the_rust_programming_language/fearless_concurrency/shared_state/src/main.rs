use std::{sync::{Mutex, Arc}, thread, rc::Rc};

fn main() {

    let counter = Rc::new(Mutex::new(5));
    let mut handles = vec![];

    for _ in 1..=10 {
        let counter = Arc::clone(&counter);
        let handle = thread::spawn(move || {
            let mut num = counter.lock().unwrap();
            *num += 1;
        });

        handles.push(handle);
    }

    for handle in handles {
        handle.join().unwrap();
    }

    println!("counter: {}", *counter.lock().unwrap());
}
