use std::{fmt::Debug, fs::File, hash::Hash, io::Write, ops::Range};

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

#[allow(dead_code)]
struct Point {
    x: i32,
    y: i32,
}

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
    // only bounds can be provided with "where" type defintion, not types (obviously, generic means
    // no type)
    return target;
}

/// a plain simple broom
struct Broom {
    x: i32,
    y: i32,
    height: i32,
}

/// a plain simple canvas to draw upon
#[allow(dead_code)]
struct Canvas {
    origin: Point,
    height: usize,
    width: usize,
}

impl Canvas {
    #[allow(unused_variables)]
    fn write_at(&self, x: i32, y: i32, to_draw: char) {
        // ... write char the canvas
    }
}

impl Broom {
    /// helper function used by Broom::draw()
    fn broomstick_range(&self) -> Range<i32> {
        self.y - self.height - 1 .. self.y
    }
}

/// A trait for characters, items and scenery - anything in the game world that's visible on
/// screen
trait Visible {
    /// Render this object object on the given canvas
    fn draw(&self, canvas: &mut Canvas);

    /// Return true if clicking at (x, y) should select this object
    /// select this object
    fn hit_test(&self, x: i32, y: i32) -> bool;
}

impl Visible for Broom {
    fn draw(&self, canvas: &mut Canvas) {
        for y in self.broomstick_range() {
            canvas.write_at(self.x, y, '|');
        }
        canvas.write_at(self.x, self.y, 'M');
    }

    fn hit_test(&self, x: i32, y: i32) -> bool {
        self.x == x && self.y - self.height - 1 <= y && y <= self.y
    }
}

/* default methods */
/// A writer that ignores whatever data you write
struct Sink { }

impl Write for Sink {
    fn write(&mut self, buf: &[u8]) -> Result<usize> {
        // claim to have successfully written whatever provided
        Ok(buf.len())
    }

    fn flush(&mut self) -> Result<()> {
        // there's nothing to flush actually, so just get the f... out
        Ok(())
    }
}

fn main() {
    let mut local_file = File::create("hello.txt").unwrap();
    say_hello(&mut local_file).unwrap();
    // say_hello::<File>(&mut local_file).unwrap();  // this is what it is indirectly with generic

    let mut bytes = vec![];
    say_hello(&mut bytes).unwrap();
    assert_eq!(bytes, b"hello world\n");

    let mut out = Sink{};
    out.write_all(b"Hello World\n").unwrap();  // where's write_all() defined ?
}
