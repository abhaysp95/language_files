fn main() {
    let mut s = String::from("Test");
    heap_example(&mut s);
}

fn heap_example(input: &mut String) {
    let mystr: &mut String = input;
    let _otherstr = mystr;  // now, ownership for mystr reference is moved to _otherstr, you can't use mystr now
    println!("{}", mystr);
}
