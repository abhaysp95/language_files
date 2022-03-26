pub fn add_two(a: i32) -> i32 {
    internal_adder(a, 2)
}

fn internal_adder(a: i32, b: i32) -> i32 {
    a + b
}

#[cfg(test)]
mod tests {

    use super::internal_adder;

    #[test]  // unit test
    fn internal() {
        assert_eq!(4, internal_adder(2, 2));
    }
}


// Only library crates exposes functions that other crates can use; binary crates are meant to be run on their own
