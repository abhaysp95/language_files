fn main() {
    let v1 = vec![1, 2, 3, 4, 5];
    let v2 = vec![1, 2];

    println!("{:?}", longer_vector(&v1, &v2));
}

// A key insight here is that  we do not need to know the lifetimes of all the references at
// compile time. We need to make sure that following things hold true:
// 1. The two inputs should have the same lifetimes since we want to compare their lengths in the function
// 2. The return value should have the same lifetime as that of the input, which is the longer of the two
fn longer_vector<'b>(x: &'b[i32], y: &'b[i32]) -> &'b[i32] {
    if x.len() > y.len() { x } else { y }
}

// Question: what does 'a or 'b signifies ? (can we put any char for annotation of lifetime ?)
