fn _moves_and_indexed_content() {

    let mut v = Vec::new();
    for i in 101..106 {
        v.push(i.to_string())
    }

    // pull out random elements from vector
    /* let _third = v[2];  // not possible moving here
    let _fifth = v[4]; */

    // 3 different ways to do so (there are more bt these are example)
    // 1. Pop a value off the end of the vector
    let fifth = v.pop().expect("vector empty!");
    assert_eq!(fifth, "105");

    // 2. Move a value out of a given index in the vector, and move the last element into its spot
    let second = v.swap_remove(1);  // to preserver ordering use remove()
    assert_eq!(second, "102");

    // 3. Swap in another vale for the one we're taking out
    let third = std::mem::replace(&mut v[2], "substitute".to_string());
    assert_eq!(third, "103");

    assert_eq!(v, vec!["101", "104", "substitute"]);
}

#[derive(Copy, Clone)]
struct Label { number: u32 }

fn print_label(l: Label) {
    println!("STAMP: {}", l.number);
}

fn _copy_types() {
    let l = Label { number: 10 };
    print_label(l);
    println!("My label number is: {}", l.number);  // can't use unless Label has copy traits
}

// this will not work, because String is not implement Copy trait
/* #[derive(Copy, Clone)]
struct StringLabel { name: String } */

fn main() {
    println!("Hello, world!");
}
