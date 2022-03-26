// because the operator(>) is defined as a default method on the standard library trait std::cmp::PartialOrd, we need to specify 'PartialOrd' in the trait bounds for T so the largest function can work on slices of any type we can compare

//fn largest<T>(list: &[T]) -> T {
// changed signature would look like this
fn largest<T: PartialOrd + Copy>(list: &[T]) -> T {
    // by using Copy trait too, this function can be used for the types that implement Copy trait only(like i32 and char)
    let mut largest = list[0];

    for &item in list {
        if item > largest {
            largest = item
        }
    }
    largest
}

// alternate solution
fn largest_ref<T: PartialOrd>(list: &[T]) -> &T {
    let mut largest = &list[0];

    for item in list {
        if item > &largest {
            largest = &item;
        }
    }
    &largest
}

#[derive(Debug)]
struct Point<T, U> {  // can have different generic parameters too(I think)
    x: T,
    y: U,
}

// can use generic type parameter with enum definition too


// in method definition
impl<T, U> Point<T, U> {
    fn x(&self) -> &T {
        &self.x
    }

    // generic type parameters in struct definition aren't always the same as those you use in the struct's method signature
    fn mixup<V, W>(self, other: Point<V, W>) -> Point<T, W> {
        Point {
            x: self.x,
            y: other.y,
        }
    }
}

// when giving concrete type for struct with generic parameter/s, mentioned function/method will only be avaiable to that concrete type(or to say, where generic type will be equal to that concrete type)
impl Point<f32, f32> {
    fn distance_from_origin(&self) -> &f32 {
        &(self.x.powi(2) + self.y.powi(2)).sqrt()
    }
}

fn main() {
    let number_list = vec![34, 50, 25, 100, 65];

    let result = largest(&number_list);
    println!("The largest number is {}", result);

    let char_list = vec!['y', 'm', 'a', 'q'];

    let result = largest(&char_list);
    println!("The largest char is {}", result);

    let both_integer = Point { x: 5, y: 10 };
    let both_float = Point { x: 1.0, y: 4.0 };
    let integer_and_float = Point { x: 1, y: 4.0 };

    {
        let p = Point { x: 5, y: 10 };
        println!("p.x = {}", p.x());
    }
    // println!("p.x = {}", p.x());  // will not work, cause x() is returning borrowed reference(&T)

    let p1 = Point { x: 5, y: 10.4 };
    let p2 = Point { x: "Hello", y: 'c' };

    let p3 = p1.mixup(p2);
    println!("p3: {:#?}", p3);
}
