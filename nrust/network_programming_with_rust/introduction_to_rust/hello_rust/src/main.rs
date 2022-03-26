extern crate term;

// Question: What's the difference in doing 'extern crate term;' & 'use term;'

fn main() {
    let mut t = term::stdout().unwrap();
    t.fg(term::color::GREEN).unwrap();
    write!(t, "hello, ").unwrap();

    t.fg(term::color::RED).unwrap();
    writeln!(t, "world!!!").unwrap();

    t.reset().unwrap();
}
