struct CustomSmartPointer {
    data: String,
}

impl Drop for CustomSmartPointer {
    // Drop trait requires to implement 'drop' method which takes '&mut self' as parameter
    fn drop(&mut self) {
        println!("Dropping CustomSmartPointer with data: {}!", self.data);
    }
}

fn main() {
    let c = CustomSmartPointer {
        data: String::from("my stuff"),
    };
    let _d = CustomSmartPointer {
        data: String::from("other stuff"),
    };
    println!("CustomSmartPointer created.");

    // early drop
    // c.drop();  // explicit destructor calls not allowed(there will be possiblity of double free)
    drop(c);
    println!("CustomSmartPointer dropped before end of main");
}
