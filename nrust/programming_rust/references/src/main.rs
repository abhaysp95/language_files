use std::collections::HashMap;


type Table = HashMap<String, Vec<String>>;

fn show(table: &Table) {
    // iterating over shared reference to HashMap is defined to produce shared references to
    // each entry's key and value: 'artist' has changed from 'String' to '&String' and 'works'
    // for 'Vec<String>' to '&Vec<String>'
    for (artist, works) in table {
        println!("works by {}", artist);
        for work in works {  // work is now a &String
            println!(" {}", work);
        }
    }
}

fn sort_works(table: &mut Table) {
    for (_artist, works) in table {
        works.sort_unstable();
        works.reverse();  // small letters come first now
    }
}

struct Anime {
    name: &'static str,
    bechdel_pass: bool,
}

fn factorial(n: usize) -> usize {
    (1..=n).product()
}

static mut STASH: &i32 = &128;
fn _f(p: &'static i32) {
    unsafe {
        STASH = p;
    }
}

// returning reference

// v should have at least one element
fn _smallest(v: &[i32]) -> &i32 {
    let mut s = &v[0];
    for r in &v[..] {
        if *r < *s {
            s = r;
        }
    }

    s
}
// the above smallest can actually be written out as
/* fn _smallest<'a>(v: &'a [i32]) -> &'a i32 {
   // ...
} */

// Distinct lifetimes
/* struct S<'a> {
    x: &'a i32,
    y: &'a i32,
} */
struct S<'a, 'b> {
    x: &'a i32,
    y: &'b i32,
}

fn _distinct_lifetimes() {
    let x = 10;
    let r;
    {
        let y = 20;
        {
            let s = S {
                x: &x,
                y: &y
            };
            r = s.x;
        }
    }
    println!("{}", r);
}

/* fn sum_r_sy(r: &i32, s: S) -> i32 {
    r + s.x + s.y
} */
// the above is shorthand for
fn _sum_r_xy<'a, 'b, 'c>(r: &'a i32, s: S<'b, 'c>) -> i32 {
    r + s.x + s.y
}

struct StringTable {
    elements: Vec<String>,
}

impl StringTable {
    // fn _find_by_prefix(&self, prefix: &str) -> Option<&String> {
    // the above signature is shorthand for
    fn _find_by_prefix<'a, 'b>(&'a self, prefix: &'b str) -> Option<&'a String> {
        // note: generally having a single lifetime 'a will work for above signature

        for i in 0..self.elements.len() {
            if self.elements[i].starts_with(prefix) {
                return Some(&self.elements[i]);
            }
        }

        None
    }
}

// wreak havoc
fn extend(vec: &mut Vec<f64>, slice: &[f64]) {
    for elt in slice {
        vec.push(*elt);
    }
}

fn _extend_usage() {
    let mut wave = Vec::new();
    let head = vec![0.0, 1.0];
    let tail = [0.0, -1.0];

    extend(&mut wave, &head);
    extend(&mut wave, &tail);

    assert_eq!(wave, vec![0.0, 1.0, 0.0, -1.0]);

    /* extend(&mut wave, &wave);  // not correct
    assert_eq!(wave, vec![0.0, 1.0, 0.0, -1.0,
               0.0, 1.0, 0.0, -1.0]); */
}

/* struct File {
    descriptor: i32
}

fn _new_file(d: i32) -> File {
    File {
        descriptor: d
    }
}

fn clone_from(this: &mut self, rhs: &File) {
    close(this.descriptor);
    this.descriptor = dup(rhs.descriptor);
} */

fn main() {
    let mut table = Table::new();
    table.insert("Gesualdo".to_string(), vec!["many madrigals".to_string(), "Tenebrae Responsoria".to_string()]);
    table.insert("Carvaggio".to_string(), vec!["The Musicians".to_string(), "The Calling of St. Matthew".to_string()]);
    table.insert("Cellini".to_string(), vec!["Perseus with the head of Medusa".to_string(), "a salt cellar".to_string()]);

    // show(&table);

    assert_eq!("The Musicians", table["Carvaggio"][0]);

    sort_works(&mut table);

    show(&table);

    let aria = Anime {
        name: "Aria: The Animation",
        bechdel_pass: true
    };
    let anime_ref = &aria;
    assert_eq!(anime_ref.name, "Aria: The Animation");
    // is basically same to
    assert_eq!((*anime_ref).name, "Aria: The Animation");

    // same stands true for mut ref
    let mut v = vec![1973, 1968];
    v.sort();  // is same as
    (&mut v).sort();  // or
    (*v).sort();

    let x = 10;
    let y = 20;
    let mut r = &x;  // 'r' doesn't have interior mutability ie., you can't change the value of
                     // x with r (same as const int* ie., pointer to const int)

    let b = true;
    if b {
        r = &y;
    }
    assert!(*r == 10 || *r == 20);

    // to compare whether references point to same address, use std::ptr::eq (for this the
    // operands must have same type, including references

    let r = &factorial(6);
    // arithmetic operators can see through one level of references
    assert_eq!(r + 1009, 1729);  // same as
    assert_eq!(r + &1009, 1729);
}
