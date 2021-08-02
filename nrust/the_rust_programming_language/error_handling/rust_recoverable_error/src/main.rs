use std::fs::File;
use std::io::{self, Read};
use std::error::Error;

fn main() -> Result<(), Box<dyn Error>> {
    // let f: u32 = File::open("hello.txt");  // used this line to get the return type for 'f' from compiler error message
    // return type is std::result::Result<File, std::io::Error>

    // so, we'll write the above line in this way
    //let f = File::open("hello.txt");
    //let f = match f {
        //Ok(file) => file,
        //Err(error) => panic!("Problem opening the file: {:?}", error)
    //};

    // using inner match
    let f = File::open("hello.txt");
    let f = match f {
        Ok(file) => file,
        Err(error) => match error.kind() {
            std::io::ErrorKind::NotFound => match File::create("hello.txt") {
                Ok(fc) => fc,
                Err(e) => panic!("Can't create file: {:?}", e),
            }
            other_error => panic!("Can't open file: {:?}", other_error)
            // is other_error working here as '_'(meaning that, match is exhaustive and like '_' is
            // used to cover rest of the arms, it is done by 'other_error' here), but is a variable
            // which can be used
        },
    };


    // if the Result value is the Ok variant, unwrap will return the value inside the Ok. If the Result is the Err variant, unwrap will call the panic! macro
    let f = File::open("hello.txt").unwrap();


    // using 'expect', instead of unwrap
    let f = File::open("hello.txt").expect("Failed to open hello.txt");

    let f = File::open("hello.txt")?;

    Ok(())
}


fn _read_username_from_file() -> Result<String, io::Error> {
    let f = File::open("hello.txt");

    let mut f = match f {
        Ok(file) => file,
        Err(e) => return Err(e),
    };

    let mut s = String::new();

    match f.read_to_string(&mut s) {
        Ok(_) => Ok(s),
        Err(e) => Err(e),
    }
}


// A shortcut for propagating errors: the '?' operator
fn _read_username_from_file2() -> Result<String, io::Error> {
    let mut f = File::open("hello.txt")?;
    let mut s = String::new();
    f.read_to_string(&mut s)?;
    Ok(s)
}
// with '?' after Result, when it is Ok variant, the value inside Ok will get returned from the expression, and program will continue. If the value is Err, the Err will be returned from the whole function as if we had used the return keyword so the value gets propogated to the calling code


// even shorter(by chaining)
fn _read_username_from_file3() -> Result<String, io::Error> {
    let mut s = String::new();
    File::open("hello.txt")?.read_to_string(&mut s)?;
    Ok(s)
}
