/// A rectangle of eight-bit grayscale pixels
/* struct GrayscaleMap {
    pixels: Vec<u8>,
    size: (usize, usize),
} */

use std::{rc::Rc, cell::{Cell, RefCell}, fs::File, io::Write};

struct Broom {
    name: String,
    height: u32,
    health: u32,
    position: (f32, f32, f32),
    intent: BroomIntent,
}

#[derive(Clone, Copy)]
enum BroomIntent {
    FetchWater,
    DumpWater,
}

fn chop(b: Broom) -> (Broom, Broom) {
    let mut broom1 = Broom {
        height: b.height / 2,
        .. b
    };

    // necessary for BroomIntent to have Copy trait (because partial move occurs here)
    let mut broom2 = Broom {
        name: broom1.name.clone(),
        .. broom1
    };

    broom1.name.push_str("I");
    broom2.name.push_str("II");

    (broom1, broom2)
}

#[test]
fn test_broom_chop() {
    let hokey = Broom {
        name: "Hokey".to_string(),
        height: 60,
        health: 100,
        position: (100.0, 200.0, 0.0),
        intent: BroomIntent::FetchWater,
    };

    let (hokey1, hokey2) = chop(hokey);
    assert_eq!(hokey1.name, "HokeyI");
    assert_eq!(hokey1.height, 30);
    assert_eq!(hokey1.health, 100);

    assert_eq!(hokey2.name, "HokeyII");
    assert_eq!(hokey2.height, 30);
    assert_eq!(hokey2.health, 100);
}

/// A first-in, first-out queue of characters
pub struct Queue {
    older: Vec<char>,  // older elements, eldest last
    younger: Vec<char>  // younger elements, youngest last
}

impl Queue {
    /// Push a character onto the back of a queue
    pub fn push(&mut self, c: char) {
        self.younger.push(c);
    }

    /// Pop a character off the front of a queue. Return 'Some(c)' if there was a character to
    /// pop, or 'None' if the queue was empty
    pub fn pop(&mut self) -> Option<char> {
        if self.older.is_empty() {
            if self.younger.is_empty() {
                return None;
            }

            // Bring the elements in younger over to older, and put them in the promised order
            use std::mem::swap;
            swap(&mut self.older, &mut self.younger);
            self.older.reverse();
        }

        self.older.pop()
    }

    pub fn is_empty(&self) -> bool {
        self.older.is_empty() && self.younger.is_empty()
    }

    pub fn split(self) -> (Vec<char>, Vec<char>) {
        (self.older, self.younger)
    }
}

pub struct Queue2<T> {
    older: Vec<T>,
    younger: Vec<T>,
}

impl<T> Queue2<T> {
    // pub fn new() -> Queue2<T> {
    pub fn new() -> Self {
        Queue2 { older: Vec::new(), younger: Vec::new() }
    }

    pub fn push(&mut self, t: T) {
        self.younger.push(t);
    }

    pub fn is_empty(&self) -> bool {
        self.older.is_empty() && self.younger.is_empty()
    }
}

impl Queue2<f64> {  // impl block for specific type
    fn sum(&self) -> f64 {
        return 0.0f64
    }
}

struct Node {
    tag: String,
    children: Vec<Rc<Node>>
}

impl Node {
    fn new(tag: &str) -> Node {
        Node {
            tag: tag.to_string(),
            children: vec![],
        }
    }

    fn append_to(self: Rc<Self>, parent: &mut Node) {
        // parent.children.push(Rc::new(self));
        parent.children.push(self);
    }
}

#[derive(Debug)]
struct Extrema<'elt> {
    greatest: &'elt i32,
    least: &'elt i32,
}

// rust inferred lifetime here automatically (because both greatest and smallest have same lifetime as Extrema), slice and Extrema are having same (& single) lifetime inferred by rust
/* fn find_extrema(slice: &[i32]) -> Extrema {
    let mut greatest = &slice[0];
    let mut least = &slice[0];

    for i in 1..slice.len() {
        if &slice[i] > greatest { greatest = &slice[i]; }
        if &slice[i] < least { least = &slice[i]; }
    }

    Extrema { greatest, least }
} */
// here's the lifetime version
fn find_extrema<'s>(slice: &'s [i32]) -> Extrema<'s> {
    let mut greatest = &slice[0];
    let mut least = &slice[0];

    for i in 1..slice.len() {
        if &slice[i] > greatest { greatest = &slice[i]; }
        if &slice[i] < least { least = &slice[i]; }
    }

    Extrema { greatest, least }
}

#[derive(Copy, Clone, Debug, PartialEq)]
// Each of these traits can be implemented automatically for a struct, provided that each of its fields implements the trait (like both of type f64, implement PartialEq)
struct Point {
    x: f64,
    y: f64,
}

pub struct SpiderRobot {
    species: String,
    web_enabled: bool,
    leg_devices: [fd::FileDesc; 8],
    hardware_error_count: Cell<u32>,
    log_file: RefCell<File>,
}

struct Camera;
struct Accelerometer;

pub struct SpiderSense {
    robot: Rc<SpiderRobot>,
    eyes: [Camera; 32],
    motion: Accelerometer,
}

impl SpiderRobot {
    /// Increase the error count by 1
    pub fn add_hardware_error(&self) {
        let n = self.hardware_error_count.get();
        self.hardware_error_count.set(n + 1);
    }

    /// write a line to the log file
    pub fn log(&self, message: &str) {
        let mut file = self.log_file.borrow_mut();
        // 'writeln!()' is like 'println!()', but sends output to the given file
        writeln!(file, "{}", message).unwrap();
        // writeln!(*file, "{}", message).unwrap();
    }
}

fn main() {
    /* let mut parent_node = Rc::new(Node::new("zero"));
    let shared_node = Rc::new(Node::new("first"));
    shared_node.append_to(&mut parent_node);  // <-- error here */

    /* let shared_node = Rc::new(Node::new("first"));
    shared_node.clone().append_to(&mut parent); */

    /* let owned = Node::new("owned directly");
    Rc::new(owned).append_to(&mut parent); */

    // let mut q = Queue2::<char>::new();
    // but rust can figure out on its own too
    /* let mut q = Queue2::new();
    q.push(0.74); */
    // q.push("CAD");  // mismatched, because rust figured out q to be of type f64

    /* let arr = [40, 20, 30, 50, 90, 10];
    let extrema = find_extrema(&arr);

    println!("{:?}", extrema); */

    let ref_cell: RefCell<String> = RefCell::new("hello".to_string());

    { // to panic remove this block
        let r = ref_cell.borrow();
        let count = r.len();
        assert_eq!(count, 5);
    } // the check is runtime (unlike normal references)
    // generally use "try_borrow() or "try_borrow_mut()" before borrowing

    let mut w = ref_cell.borrow_mut(); // panic: already borrowed
    w.push_str(" world");
}
