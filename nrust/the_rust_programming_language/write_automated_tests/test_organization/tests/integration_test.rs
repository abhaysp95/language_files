use test_organization;

mod common;

//We’ve added use adder at the top of the code, which we didn’t need in the unit tests. The reason is that each file in the tests directory is a separate crate, so we need to bring our library into each test crate’s scope.

#[test]
fn it_adds_two() {
    common::setup();
    assert_eq!(4, test_organization::add_two(2));
}
