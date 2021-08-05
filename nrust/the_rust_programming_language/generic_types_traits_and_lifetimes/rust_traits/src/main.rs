// rust traits are like interface from some other languages

pub trait Summary {
    //fn summarize(&self) -> String;  // signature
    // trait with default implementation
    fn summarize(&self) -> String {  // default implementation
        format!("Read more from {}...", self.summarize_author())
    }

    fn summarize_author(&self) -> String;
}

// the compiler will enforce that any type that has the 'Summary' trait will have the method 'summarize' defined with this signature exactly

pub struct NewsArticle {
    pub headline: String,
    pub location: String,
    pub author: String,
    pub content: String,
}

impl Summary for NewsArticle {
    fn summarize(&self) -> String {
        format!("{} by {} ({})",
            self.headline, self.author, self.location)
    }

    fn summarize_author(&self) -> String {
        format!("@{}", self.author)
    }
}
// to use a default implementation to summarize instances of NewsArticle instead of defining a custom implementation, we specify an empty impl block
//impl Summary for NewsArticle {}

pub struct Tweet {
    pub username: String,
    pub content: String,
    pub reply: bool,
    pub retweet: bool,
}

impl Summary for Tweet {
    fn summarize(&self) -> String {
        format!("{}: {}", self.username, self.content)
    }

    fn summarize_author(&self) -> String {
        format!("@{}", self.username)
    }
}

use std::fmt::Error;
impl Display for NewsArticle {  // don't pay attention to content of this block(I'm not good yet), but what it says is that since, I'm calling notify for NewsArticle with multiple tratis(Summary + Display), I've to implement Display trait for type NewsArticle
    fn fmt(&self, _f: &mut std::fmt::Formatter<'_>) -> std::fmt::Result {
        let e = Error { };
        match !self.content.is_empty() {
            true => Ok(()),
            false => Err(e)
        }
    }
}

// after implementing the trait, we can call the methods on instance of 'NewsArticle' and 'Tweet' in the same way we call regular methods

fn main() {
    let tweet = Tweet {
        username: String::from("horse_ebooks"),
        content: String::from("Ofcourse, as you probably already know"),
        reply: false,
        retweet: false,
    };

    println!("1 new tweet: {}", tweet.summarize());

    let article = NewsArticle {
        headline: String::from("Penguins win the Stanley Cup Championship"),
        location: String::from("Pittsburgh, PA, USA"),
        author: String::from("Iceburgh"),
        content: String::from("The Pittsburgh Penguins once again are the best \
                              hockey team in the NHL"),
    };

    println!("New article available! {}", article.summarize());

    notify(&tweet);

    notify7(&article);
}


// One restriction to note with trait implmentations is that we can implement a trait on a type only if either the trait or the type is local to our crate


// Note that it isn't possible to call the default implementation from an overriding implementation of the same method

pub fn notify(item: &impl Summary) {
    // this parameter(&impl Summary) accepts any type that implements the specfied trait(Summary)
    println!("Breaking news! {}", item.summarize());
}

// trait bound syntax
// the 'impl Trait' syntax is actually syntax sugar fro longer form(known as Trait Bound).
pub fn _notify2<T: Summary>(_item: &T) {
    // -- snip --
}

// more comparision between these two
pub fn _notify3(_item1: &impl Summary, _item2: &impl Summary) {
    // --snip--
}
// if we wanted this function(above one) to allow _item1 and _item2 to have different types, using impl Trait would be appropriate(as long as both type implement Summary). If we wanted to force both parameters to have the same type, that's only possible to express using a trait bound
pub fn _notify4<T: Summary>(_item1: &T, _item2: &T) {
    // --snip--
}

// testing(this will also work)
pub fn _notify5<T: Summary, U: Summary>(_item1: &T, _item2: &U) {
    // --snip--
}


// specifying multiple trait bounds with + syntax
use std::fmt::Display;
pub fn _notify6(_item: &(impl Summary + Display)) {  }
// or with trait bounds on generic types
pub fn notify7<T: Summary + Display>(item: &T) {
//pub fn notify7<T: Summary>(item: &T) {
    println!("{:?}", item.summarize());
}
// with the two trait bounds specified, the body of _notify# can call 'summarize' and use {} to format item


// clearer trait bounds with where clauses
use std::fmt::Debug;
fn _some_function<T: Display + Clone, U: Clone + Debug>(_t: &T, _u: &U) -> i32 { 0 }
// we can use 'where' clause
fn _some_function2<T, U>(_t: &T, _u: &U) -> i32
    where T: Display + Clone,
          U : Clone + Debug { 0 }


// the ability to return a type that is only specified by the trait it implements is especially useful in context of closures and iterators
fn _returns_summarizable(t: Tweet) -> impl Summary {
    Tweet {
        ..t  // too lazy to type, that's why parameter and this
    }
}

// however, you can only use 'impl Trait' if you're returning a single type
// below code will not work
//fn _returns_summarizable2(switch: bool, t: Tweet, u: NewsArticle) -> impl Summary {
    //if switch {
        //NewsArticle {
            //..u
        //}
    //} else {
        //Tweet {
            //..t
        //}
    //}
//}


// using trait bounds to conditionally implement methods
struct Pair<T> {
    x: T,
    y: T,
}

impl<T> Pair<T> {
    fn new(x: T, y: T) -> Self {
        Self { x, y }
    }
}

// Pair<T> only implements the cmp_display method if its inner type T implements PartialOrd trait that enables comparision and the Display trait that enables printing
impl<T: Display + PartialOrd> Pair<T> {
    fn cmp_display(&self) {
        if self.x >= self.y {
            println!("The largest member is x: {}", self.x);
        }
        else {
            println!("The largest member is y: {}", self.y);
        }
    }
}


// We can also conditionally implement a trait for any type that implements another trait. Implementations of a trait on any type that satisfies the trait bounds are called 'blanket implementations'.
// E.g., the std. lib implements the ToString trait on any type that implemenets the Display trait. The impl block in the std. lib looks similar to this code
//impl<T: Display> ToString for T {
     //--snip--
//}

// now, because of blanket Implementation, we can call the to_string method defined by the ToString trait on any type that implements the Display Trait
// let s = 3.to_string();
