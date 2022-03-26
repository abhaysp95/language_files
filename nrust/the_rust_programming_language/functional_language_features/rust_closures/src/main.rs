use std::thread;
use std::time::Duration;

fn simulated_expensive_calculation(intensity: u32) -> u32 {
    println!("Calculating slowly...");
    thread::sleep(Duration::from_secs(2));
    intensity
}

fn main() {
    let simulated_user_specified_value = 10;
    let simulated_random_number = 7;

    generate_workout(simulated_user_specified_value, simulated_random_number);
}

// vertical comparision, closure and function
//fn add_one_v1    (x: u32) -> u32 { x + 1 }
//let add_one_v2 = |x: u32| -> u32 { x + 1 };
//let add_one_v3 = |x|             { x + 1 };
//let add_one_v4 = |x|               x + 1


// calling is must for 'add_one_v3' and 'add_one_v4' to compile the program, because the type will be inferred from thier usage


// closure definitions will have one concrete type inferred for each of thier parameters and for their return values
fn test_closure_type() {
    // attempting to call a closure whose types are inferred with two different types
    let example_closure = |x| x;
    let _s = example_closure(String::from("hello"));  // after this, type 'String' gets locked into the closure 'example_closure'
    // let _n = example_closure(5);  // error here, expected string, found integer
}

// capturing the envirorment with closures
fn _env_test() {
    let x = 4;
    let equal_to_x = |z| z == x;
    // here, even though 'x' is not one of the parameters of 'equal_to_x', the 'equal_to_x' closures is allowed to se the 'x' variable that's defined in the same scope that 'equal_to_x' is defined in

    let y = 4;

    assert!(equal_to_x(y));
}
// we can't do same(above) thing with function

fn _env_test2() {
    let x = 4;
    //fn equal_to_x(z: i32) -> bool { z == x }  // can't capture x
    let y = 4;
    //assert!(equal_to_x(y));  // uncomment this(if you do 'equal_to_x' fn to see the error)
}

// closures can capture values from their environment(which is generally considered overhead), which directly map to three ways a function can take a parameter: taking ownership, borrowing mutably and borrowing immutably. These are encoded in three 'Fn' traits as follows:
// 1. FnOnce consumes the variables it captures from its enclosing scope, known as the closure’s environment. To consume the captured variables, the closure must take ownership of these variables and move them into the closure when it is defined. The Once part of the name represents the fact that the closure can’t take ownership of the same variables more than once, so it can be called only once.
// 2. FnMut can change the environment because it mutably borrows values.
// 3. Fn borrows values from the environment immutably.

fn _env_var_move() {
    let x = vec![1, 2, 3];
    let equal_to_x = move |z| z == x;

    // move occurs because 'x' has type Vec<i32>, which does not implement Copy trait
    // variable moved to use in closure

    // println!("Can't use x here: {:?}", x);  // can't use x now

    let y = vec![1, 2, 3];
    assert!(equal_to_x(y));
}


// memoizaition or lazy evaluation

// to make a struct that holds a closure,we need to specify the type of the closure, because a struct definition needs to know the types of each of its fields. Each closure instance has its own unique anonymous type: that is, even if two closures have the same signature, their types are still considered different.To define structs, enums or function parameters that use closures, we use generics and trait bounds

// The 'Fn' trait are provided by the std. lib. All closures implement at least one of the traits: 'Fn, FnMut, FnOnce'.

// 'T: Fn(u32) -> u32', refer to parameter for closure 'calculation', not for struct

// NOTE: functions can implement all three of the 'Fn' traits too. If what we want to do doesn't require capturing a value from the environment, we can use a function rather than a closure where we need something that implements a 'Fn' trait

// TODO: we might want to cache the results of closures that take a string slice and return usize value, for example. To fix this issue, try introducing more generic parameters

use std::collections::HashMap;
struct Cacher<T> where T: Fn(u32) -> u32 {
    // third iteration
    calculation: T,
    value: HashMap<u32, u32>
}

impl<T> Cacher<T> where T: Fn(u32) -> u32 {
    // second iteration
    fn new(calculation: T) -> Cacher<T> {
        Cacher {
            calculation,
            value: HashMap::new(),
        }
    }

    // third iteration
    fn value(&mut self, arg: u32) -> u32 {
        match self.value.get(&arg) {
            Some(v) => *v,
            None => {
                let v = (self.calculation)(arg);
                self.value.insert(arg, v);
                v
            }
        }
    }

    // second iteration
    //fn value(&mut self, arg: u32) -> u32 {
        //match self.value.get(&arg) {
            //Some(v) => match v {
                //Some(v) => *v,
                //None => {
                    //let v = (self.calculation)(arg);
                    //self.value.insert(arg, Some(v));
                    //v
                //}
            //},
            //None => {
                //let v = (self.calculation)(arg);
                //self.value.insert(arg, Some(v));
                //v
            //}
        //}
    //}

    // first iteration
    //fn new(calculation: T) -> Cacher<T> {
        //Cacher {
            //calculation,
            //value: None,
        //}
    //}

    //fn value(&mut self, arg: u32) -> u32 {
        //match self.value {
            //Some(v) => v,
            //None => {
                //let v = (self.calculation)(arg);
                //self.value = Some(v);
                //v
            //}
        //}
    //}
}

// limitation of our 'Cacher' implementation
// First problem is that a 'Cacher' instance assumes it will always get the same value for the parameter arg to the value method.
#[test]
fn call_with_different_values() {
    let mut c = Cacher::new(|a| a);

    let v1 = c.value(1);
    let v2 = c.value(2);

    assert_eq!(v2, 2);
}

// second problem with the current 'Cacher' implementation is that it only accepts the closures that take one parameter of type u32 and return a u32

// fifth iteration
fn generate_workout(intensity: u32, random_number: u32) {
    let mut expensive_result = Cacher::new(|num| {
        println!("calculation slowly...");
        thread::sleep(Duration::from_secs(2));
        num
    });  // passing the closure as argument to 'Cacher::new()'

    if intensity < 25 {
        println!(
            "Today, do {} pushups!",
            expensive_result.value(intensity));
        println!(
            "Next, do {} situps!",
            expensive_result.value(intensity));
    } else {
        if random_number == 3 {
            println!("Take a break today! Remember to stay hydrated!");
        } else {
            println!(
                "Today, run for {} minutes!",
                expensive_result.value(intensity));
        }
    }
}

// fourth iteration
//fn generate_workout(intensity: u32, random_number: u32) {
    // additional optional type annotations of the parameter and return value types in the closure
    //let expensive_closure = |num: u32| -> u32 {
        //println!("calculating slowly...");
        //thread::sleep(Duration::from_secs(2));
        //num
    //};

    //if intensity < 25 {
        //println!(
            //"Today, do {} pushups!", expensive_closure(intensity));
        //println!(
            //"Next, do {} situps!", expensive_closure(intensity));
    //} else {
        //if random_number == 3 {
            //println!("Take a break today! Remember to stay hydrated!");
        //} else {
            //println!(
                //"Today, run for {} minutes!",
                //expensive_closure(intensity));
        //}
    //}
//}

// third iteration
//fn generate_workout(intensity: u32, random_number: u32) {
    //let expensive_closure = |num| {
        //println!("calculating slowly...");
        //thread::sleep(Duration::from_secs(2));
        //num
    //};

    //if intensity < 25 {
        //println!(
            //"Today, do {} pushups!", expensive_closure(intensity));
        //println!(
            //"Next, do {} situps!", expensive_closure(intensity));
    //} else {
        //if random_number == 3 {
            //println!("Take a break today! Remember to stay hydrated!");
        //} else {
            //println!(
                //"Today, run for {} minutes!",
                //expensive_closure(intensity));
        //}
    //}
//}

// second iteration
//fn generate_workout(intensity: u32, random_number: u32) {
    //let expensive_result = simulated_expensive_calculation(intensity);
    //if intensity < 25 {
        //println!(
            //"Today, do {} pushups!", expensive_result);
        //println!(
            //"Next, do {} situps!", expensive_result);
    //} else {
        //if random_number == 3 {
            //println!("Take a break today! Remember to stay hydrated!");
        //} else {
            //println!(
                //"Today, run for {} minutes!", expensive_result);
        //}
    //}
//}

// first iteration
//fn generate_workout(intensity: u32, random_number: u32) {
    //if intensity < 25 {
        //println!(
            //"Today, do {} pushups!",
            //simulated_expensive_calculation(intensity)
            //);
        //println!(
            //"Next, do {} situps!",
            //simulated_expensive_calculation(intensity)
            //);
    //} else {
        //if random_number == 3 {
            //println!("Take a break today! Remember to stay hydrated!");
        //} else {
            //println!(
                //"Today, run for {} minutes!",
                //simulated_expensive_calculation(intensity)
                //);
        //}
    //}
//}

