use std::{fmt::Debug, fs::File, hash::Hash, io::Write};

#[allow(dead_code)]
// just "dyn Write" will not work, a reference is needed because of size issue
/* fn say_hello(out: &mut dyn Write) -> Result<()> {
    out.write_all(b"Hello world\n")?;
    out.flush()
} */

fn say_hello<W: Write>(out: &mut W) -> std::io::Result<()> {
    out.write_all(b"Hello World\n")?;
    out.flush()
}

#[allow(dead_code)]
fn min<T: Ord>(value1: T, value2: T) -> T {
    if value1 < value2 {
        value1
    } else {
        value2
    }
}

#[allow(dead_code)]
fn top_ten<T: Debug + Hash + Eq>(_values: &Vec<T>) {
    // ...
}

/* struct Point {
    x: usize,
    y: usize,
} */

trait MeasureDistance {}

// you can see there's no need to provide lifetime for candidates too, because lifetime of
// reference returned doesn't depend on "candidates" as per the function definition
// fn nearest<'t, P>(target: &'t P, candidates: &[P]) -> &'t P
// but let's see how to give multiple lifetimes, nonetheless
// also, lifetimes will always come first and then the bound/s
#[allow(dead_code)]
fn nearest<'t, 'c, P>(target: &'t P, _candidates: &'c [P]) -> &'t P
where
    P: MeasureDistance,
{
    // only bounds can be provided with "where" type defintion, not types
    return target
}

fn main() {
    let mut local_file = File::create("hello.txt").unwrap();
    say_hello(&mut local_file).unwrap();
    // say_hello::<File>(&mut local_file).unwrap();  // this is what it is indirectly with generic

    let mut bytes = vec![];
    say_hello(&mut bytes).unwrap();
    assert_eq!(bytes, b"hello world\n");
}
