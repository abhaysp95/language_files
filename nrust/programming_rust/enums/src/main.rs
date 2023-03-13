use std::{cmp::Ordering, collections::HashMap, mem::size_of};

enum HttpStatus {
    Ok = 200,
    NotModified = 304,
    NotFound = 404,
}

fn _http_status_from_u32(n: u32) -> Option<HttpStatus> {
    match n {
        200 => Some(HttpStatus::Ok),
        304 => Some(HttpStatus::NotModified),
        404 => Some(HttpStatus::NotFound),
        _ => None,
    }
}

#[derive(Copy, Clone, Debug, PartialEq, Eq)]
enum TimeUnit {
    Seconds,
    Minutes,
    Hours,
    Days,
    Months,
    Years,
}

impl TimeUnit {
    /// Return the plural noun for this time unit
    fn plural(self) -> &'static str {
        match self {
            TimeUnit::Seconds => "seconds",
            TimeUnit::Minutes => "minutes",
            TimeUnit::Hours => "hours",
            TimeUnit::Days => "days",
            TimeUnit::Months => "months",
            TimeUnit::Years => "years",
        }
    }

    /// Return the singular noun for this time unit
    fn singular(self) -> &'static str {
        self.plural().trim_end_matches('s')
    }
}

enum RoughTime {
    InThePast(TimeUnit, u32),
    JustNow,
    InTheFuture(TimeUnit, u32),
}

fn _rough_time_to_english(rt: RoughTime) -> String {
    use self::RoughTime::*;
    match rt {
        InThePast(units, count) => format!("{} {} ago", count, units.plural()),
        JustNow => format!("just now"),
        InTheFuture(unit, 1) => format!("{}", unit.singular()),
        InTheFuture(units, count) => format!("{} {}", count, units.plural()),
    }
}

type Point3d = (usize, usize, usize);

enum Shape {
    Sphere { center: Point3d, radius: f32 },
    Cuboid { corner1: Point3d, corner2: Point3d },
}

enum RelationshipStatus {
    Single,
    InARelationship,
    ItsComplicated(Option<String>),
    ItsExtremlyComplicated { car: u16, cdr: f32 },
}

/// An enum JSON
enum Json {
    Null,
    Boolean(bool),
    Number(f64),
    String(String),
    Array(Vec<Json>),
    Object(Box<HashMap<String, Json>>), // Box makes it take only one word (instead of taking too much space)
}
// can make other values Box wrapped too (for low space)

/// An ordered collection of 'T's
enum BinaryTree<T> {
    Empty,
    NonEmpty(Box<TreeNode<T>>),
}

/// a binary tree node
struct TreeNode<T> {
    element: T,
    left: BinaryTree<T>,
    right: BinaryTree<T>,
}

struct Account {
    name: String,
    language: String,
    status: String,
    birthday: String,
    eye_color: String,
    pet: String,
    security_questions: Vec<String>,
    hashed_innermost_secret: String,
    is_admantium_preferred_customer: bool,
}

fn get_account(id: usize) -> Option<Account> {
    unimplemented!()
}

impl Account {
    fn new() -> Self {
        unimplemented!()
    }
}

/* fn hsl_to_right(hsl: [u8; 3]) -> [u8; 3] {
    match hsl {
        [_, _, 0] => [0, 0, 0],
        [_, _, 255] => [255, 255, 255],

        // ...
    }
} */

fn greet_people(names: &[&str]) {
    match names {
        [] => { println!("Hello, nobody") },
        [a] => { println!("Hello, {}", a) },
        [a, b] => { println!("Hello, {} and {}", a, b) },
        [a, .., b] => { println!("Hello, everybody from {} to {}.", a, b) },
    }
}

struct Ui;

impl Ui {
    fn greet(&self, name: &String, language: &String) {
    }
    fn show_settings(&self, account: &Account) {
    }
}

fn main() {
    assert_eq!(size_of::<Ordering>(), 1);
    assert_eq!(size_of::<HttpStatus>(), 2);
    assert_eq!(HttpStatus::Ok as i32, 200);

    let four_score_and_seven_years_ago = RoughTime::InThePast(TimeUnit::Years, 4 * 20 + 7);
    let three_hours_from_now = RoughTime::InTheFuture(TimeUnit::Hours, 3);

    let unit_sphere = Shape::Sphere {
        center: (0, 0, 0),
        radius: 1.0,
    };

    use self::BinaryTree::*;
    let jupiter_tree = NonEmpty(Box::new(TreeNode {
        element: "Jupiter",
        left: BinaryTree::Empty,
        right: BinaryTree::Empty,
    }));
    let mercury_tree = NonEmpty(Box::new(TreeNode {
        element: "Mercury",
        left: BinaryTree::Empty,
        right: BinaryTree::Empty,
    }));

    let mars_tree = NonEmpty(Box::new(TreeNode {
        element: "Mars",
        left: jupiter_tree,  // ownership of jupiter node transferred to mars
        right: mercury_tree,
    }));


    let id = 0;
    match get_account(id) {
        Some(Account { name, language, .. }) => { println!("do something"); },
        None => { },
    }

    let account = Account::new();
    let ui = Ui;
    /* match account {  // will not work
        Account { name, language, .. } => {
            ui.greet(&name, &language);
            ui.show_settings(&account);  // because of partial move
        }
    } */

    match account {
        Account { ref name, ref language, .. } => {
            ui.greet(name, language);
            ui.show_settings(&account);
        },
    }
}
