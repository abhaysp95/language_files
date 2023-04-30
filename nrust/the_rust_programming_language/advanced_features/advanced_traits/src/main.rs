use core::fmt;
use std::{ops::Add, fmt::{Display, Debug}, slice::Join};

#[derive(Debug, PartialEq)]
struct Point {
    x: u32,
    y: u32,
}

// default type Parameter syntax, defaults to Self
impl Add for Point {
    type Output = Point;

    fn add(self, rhs: Self) -> Self::Output {
        Point {
            x: self.x + rhs.x,
            y: self.y + rhs.y,
        }
    }
}

// default type Parameter syntax, overriden for u32
impl Add<u32> for Point {
    type Output = Point;

    fn add(self, rhs: u32) -> Self::Output {
        Point {
            x: self.x + rhs,
            y: self.y + rhs,
        }
    }
}

#[derive(Debug, PartialEq, Clone)]
struct Millimeters(u32);
#[derive(Debug, PartialEq, Clone)]
struct Meters(f32);

impl Add<Meters> for Millimeters {
    type Output = Millimeters;

    fn add(self, rhs: Meters) -> Self::Output {
        Millimeters(self.0 + (rhs.0 as u32 * 1000))
    }
}

impl Add<Millimeters> for Meters {
    type Output = Meters;

    fn add(self, rhs: Millimeters) -> Self::Output {
        if rhs.0 == 0 {
            return self;
        }
        Meters(self.0 + (rhs.0 as f32 / 1000.0))
    }
}

trait Pilot {
    fn fly(&self);
}

trait Wizard {
    fn fly(&self);
}

struct Human;

impl Pilot for Human {
    fn fly(&self) {
        println!("Human pilot can fly");
    }
}

impl Wizard for Human {
    fn fly(&self) {
        println!("Human wizard can fly");
    }
}

impl Human {
    fn fly(&self) {
        println!("Human can't fly");
    }
}

trait Animal {
    fn baby_name() -> String;
}

struct Dog;

impl Dog {
    fn baby_name() -> String {
        String::from("Rover")
    }
}

impl Animal for Dog {
    fn baby_name() -> String {
        String::from("Dog")
    }
}

// supertrait
trait OutlinePrint: fmt::Display {
    fn outline_print(&self) {
        let output = self.to_string();
        let len = output.len();
        println!("{}", "*".repeat(len + 4));
        println!("*{}*", " ".repeat(len + 2));
        println!("* {} *", output);
        println!("*{}*", " ".repeat(len + 2));
        println!("{}", "*".repeat(len + 4));
    }
}

impl OutlinePrint for Point { }

impl Display for Point {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        write!(f, "({}, {})", self.x, self.y)
    }
}

// Newtype pattern
struct Wrapper<T: Display>(Vec<T>);

impl<T> fmt::Display for Wrapper<T> where T: Display {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> fmt::Result {
        let v = self.0.iter().map(|x| x.to_string()).collect::<Vec<_>>();
        write!(f, "[{}]", v.join(" "))
        // write!(f, "[{}]", self.0.join(" "))
    }
}

fn main() {
    assert_eq!(
        Point { x: 1, y: 0 } + Point { x: 2, y: 3 },
        Point { x: 3, y: 3 }
    );

    let mm1 = Millimeters(1000);
    let mt1 = Meters(2.0);
    let mm2 = Millimeters(200);

    assert_eq!(Millimeters(3000), mm1 + mt1.clone());
    assert_eq!(Meters(2.2), mt1 + mm2);

    let human = Human;
    human.fly(); // defaults to direct fly method related to Human
    Pilot::fly(&human);
    Wizard::fly(&human);

    // but what about associated functions ? they don't have &self in parameter
    println!(
        "Dog name: {}, Trait Animal dog name: {}",
        Dog::baby_name(),
        <Dog as Animal>::baby_name()
    );
}
