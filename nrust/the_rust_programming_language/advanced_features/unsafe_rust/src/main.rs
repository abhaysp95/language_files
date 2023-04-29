use std::{ops::Add, slice};

static mut COUNTER: u32 = 10;

#[allow(dead_code)]
fn add_to_counter(num: u32) {
    unsafe {
        COUNTER += num;
    }
}

fn main() {
    let mut num = 5; // mut is needed for r2

    let r1 = &num as *const i32;
    let r2 = &mut num as *mut i32;

    unsafe {
        println!("r1 is: {}", *r1); // can't dereference raw pointer type in safe rust
        println!("r2 is: {}", *r2);
    }

    let mut v = [1, 2, 3, 4, 5, 6];

    let (a, b) = split_at_mut(&mut v[..], 3);

    println!("{:?}, {:?}", a, b);

    assert_eq!(a, &mut [1, 2, 3]);
    assert_eq!(b, &mut [4, 5, 6]);

    unsafe {
        println!("absolute value of -3, C FFI: {}", abs(-3));
    }

    add_to_counter(10); // doesn't require unsafe block

    unsafe {
        println!("COUNTER: {}", COUNTER);
    }
}

/* fn split_at_mut(values: &mut [i32], mid: usize) -> (&mut [i32], &mut [i32]) {
    let len = values.len();

    assert!(mid <= len);

    (&mut values[..mid], &mut values[mid..])  // borrowing same slice two time (even though
                                              // different parts, rust compiler doesn't understand
                                              // it
} */

fn split_at_mut(values: &mut [i32], mid: usize) -> (&mut [i32], &mut [i32]) {
    let len = values.len();
    let ptr = values.as_mut_ptr();

    assert!(mid <= len);

    unsafe {
        (
            slice::from_raw_parts_mut(ptr, mid),
            slice::from_raw_parts_mut(ptr.add(3), len - mid),
        )
    }
}

extern "C" {
    fn abs(input: i32) -> i32;
}
