fn main() {
    let _v: Vec<i32> = Vec::new();

    let _v_macro = vec![1, 2, 3];  // we don't explicitly need to specify the type here, because we're initializing it from start

    // updating a vector
    let mut mut_v = Vec::new();
    mut_v.push(6);
    // mut_v.push(10.02);  // this will give mismatched type, since rust inferred 'i32' as datatype for 'mut_v' from pushing '6'

    {
        let v = vec![1, 2, 3];
        // v goes out of scope and is free here
    }

    // reading
    let v = vec![1, 2, 3, 4, 5];

    let third: &i32 = &v[2];
    println!("The third element is {}", third);

    // by using & and [], gives us a reference, or by using the 'get' method with the index passed an an argument, gived us an 'Option<&T>'(enum)

    match v.get(2) {
        Some(third) => println!("The third element is {}", third),
        None => println!("There is not third element"),
    }

    let _does_not_exist = v.get(100);  // it returns None, without panic
    let _does_not_exist = &v[100];  // cause panic, because it references a nonexistent element


    //let first = &mut_v[0];  // immutable reference
    let first = &mut mut_v[0];  // mutable reference
    // mut_v.push(10);  // whether you borrow it as mutable or immutable reference, it will still be a problem, because of ownership rules
    println!("The first element is: {}", first);  // but if we put this line one above, it'll work


    // iterating over the values in a vector
    for i in &mut_v {
        println!("{}", i);
    }

    // we can also iterate over mutable reference
    for i in &mut mut_v {
        *i *= 10;  // you need to dereference 'i'
        println!("{}", i);
    }

    enum SpreadsheetCell {
        Int(i32),
        Float(f64),
        Text(String),
    }

        // I explicitly wrote type for '_row' for making it clear, that vector is of one type only
    let _row: Vec<SpreadsheetCell> = vec![
        SpreadsheetCell::Int(3),
        SpreadsheetCell::Text(String::from("blue")),
        SpreadsheetCell::Float(10.32),
    ];
}
