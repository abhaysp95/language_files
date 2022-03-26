fn _basic_iterator() {
    let v1 = vec![1, 2, 3];
    let vi_iter = v1.iter();  // iterator is stored in 'vi_iter', and no iteration takes place at that time
    for val in vi_iter {
        println!("Got: {}", val);
    }
}

// the 'Iterator Trait' and the 'next' method
// All iterators implement 'Iterator' trait(defined in std. lib) which looks like this
pub trait Iterator {
    type Item;
    fn next(&mut self) -> Option<Self::Item>;
    // --snip--
}

// the Iterator trait only requires the implementors to define one method: the 'next' method

#[test]
fn iterator_demonstration() {
    let v1 = vec![1, 2, 3];
    let mut v1_iter = v1.iter();
    // we didn't need to make 'v1_iter' mutable for 'for' loop because the loop took ownership of 'v1_iter' and made it mutable behind the scene
    // next returns immutable references to the values in the vector. The 'iter()' method produces an iterator over immutable references. If we want to create an iterator that takes ownership of 'v1' and returns owned valued, we can call 'into_iter()' instead of 'iter'. Similarily, if we want to iterate over mutable references, we can call 'iter_mut' instead of 'iter'

    assert_eq!(v1_iter.next(), Some(&1));
    assert_eq!(v1_iter.next(), Some(&2));
    assert_eq!(v1_iter.next(), Some(&3));
    assert_eq!(v1_iter.next(), None);
}

fn main() {
    println!("Hello, world!");
}


// methods that consume the iterator
// Methods that call 'next' are called 'consuming adaptors', because calling them uses up the iterator(because 'next()' consumens iterator)

#[test]
fn iterator_sum() {
    let v1 = vec![1, 2, 3];

    let v1_iter = v1.iter();

    let total: i32 = v1_iter.sum();
    // we aren't allowed to use 'v1_iter' after the call to 'sum' because 'sum' takes ownership of the iterator we call it on(explained in above comment)

    assert_eq!(total, 0);
}

// methods that produce other iterators
fn iter_map() {
    let v1: Vec<i32> = vec![1, 2, 3];
    v1.iter().map(|x| x + 1); // iterators are lazy(and so closure isn't used)
    // to fix this, we'll use 'collect()' method. This method consumes the iterator and collects the resulting values into a collection data type
}

fn iter_map_redefined() {
    let v1: Vec<i32> = vec![1, 2, 3];
    let v2: Vec<_> = v1.iter().map(|x| x + 1).collect();
    assert_eq!(v2, vec![2, 3, 4]);
}


// Using closures that capture their environment
// The 'filter()' method on an iterator takes a closure that takes each item from the iterator and returns a Boolean. If the closure returns 'true', the value will be included in the iterator produced by 'filter'. If the closure returns 'false', the value won't be included in the resulting iterator
#[derive(PartialEq, Debug)]
struct Shoe {
    size: u32,
    style: String,
}

fn shoes_in_size(shoes: Vec<Shoe>, shoe_size: u32) -> Vec<Shoe> {
    shoes.into_iter().filter(|s| s.size == shoe_size).collect()
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn filters_by_size() {
        let shoes = vec![
            Shoe {
                size: 10,
                style: String::from("sneaker"),
            },
            Shoe {
                size: 13,
                style: String::from("sandal"),
            },
            Shoe {
                size: 10,
                style: String::from("boot"),
            },
        ];

        let in_my_size = shoes_in_size(shoes, 10);

        assert_eq!(
            in_my_size,
            vec![
                Shoe {
                    size: 10,
                    style: String::from("sneaker"),
                },
                Shoe {
                    size: 10,
                    style: String::from("boot"),
                },
            ]
        );
    }
}


// Creating our own iterators with the 'Iterator' trait

// You can create an iterator by calling 'iter', 'into_iter' or 'iter_mut' on a vector or other collection types in the std lib like HashMap. You can also create iterators that do anything you want by implementing the 'Iterator' trait on your own types.

struct Counter {
    count: u32,
}

impl Counter {
    fn new() -> Counter {
        Counter { count: 0 }
    }
}
// implement 'Iterator' trait
impl Iterator for Counter {
    type Item = u32;
    fn next(&mut self) -> Option<Self::Item> {
        if self.count < 5 {
            self.count += 1;
            Some(self.count)
        } else {
            None
        }
    }
}
// we set the associated type 'Item' type for our iterator to 'u32', meaning the iterator will return 'u32' values

#[test]
fn calling_next_directly() {
    let mut counter = Counter::new();

    assert_eq!(counter.next(), Some(1));
    assert_eq!(counter.next(), Some(2));
    assert_eq!(counter.next(), Some(3));
    assert_eq!(counter.next(), Some(4));
    assert_eq!(counter.next(), Some(5));
    assert_eq!(counter.next(), None);
}

// We implemented the 'Iterator' trait by defining the 'next' method, so we can use 'Iterator' trait method's default implementations as defined in the std. library, because they all use the 'next' method's functionality

#[test]
fn using_other_iterator_trait_methods() {
    let sum: u32 = Counter::new()
        .zip(Counter::new().skip(1))
        .map(|a, b| a * b)
        .filter(|x| x % 3 == 0)
        .sum();
    assert_eq!(18, sum);
}
