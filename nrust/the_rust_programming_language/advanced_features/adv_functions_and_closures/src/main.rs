fn add_one(x: i32) -> i32 {
    return x + 1
}

fn do_twice(f: fn(i32) -> i32, x: i32) -> i32 {
    f(x) + f(x)
}

fn main() {
    let answer = do_twice(add_one, 10);
    assert_eq!(22, answer);

}
