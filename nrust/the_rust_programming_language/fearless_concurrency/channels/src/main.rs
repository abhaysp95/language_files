use std::{sync::mpsc, thread, time::Duration};


fn main() {
    let (tx, rx) = mpsc::channel();

    let tx1 = tx.clone();
    thread::spawn(move || {
        let vals = vec![
            "1. hi".to_string(),
            "1. from".to_string(),
            "1. the".to_string(),
            "1. spawned".to_string(),
            "1. thread".to_string(),
        ];

        for val in vals {
            tx1.send(val).unwrap();
            thread::sleep(Duration::from_millis(100));
        }

        // println!("After sending vals: {:?}", vals);  // can't do it, vals is already moved
    });

    thread::spawn(move || {
        let vals = vec![
            "2. hi".to_string(),
            "2. from".to_string(),
            "2. the".to_string(),
            "2. spawned".to_string(),
            "2. thread".to_string(),
        ];

        for val in vals {
            tx.send(val).unwrap();
            thread::sleep(Duration::from_millis(100));
        }
    });

    for msg in rx {
        println!("received: {msg}");
    }
}
