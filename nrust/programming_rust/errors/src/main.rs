use core::fmt;
// use std::error::Error;
use std::{io::{Write, stderr, BufRead, self}, error::Error};

/// Dump an error message to `stderr`
///
/// If another error happens while building the error message or writing to `stderr`, it
/// is ignored
/* fn _print_error(mut err: &dyn Error) {
    let _ = writeln!(stderr(), "error: {}", err);
    while let Some(source) = err.source() {
        let _ = writeln!(stderr(), "caused by: {}", source);
        err = source;
    }
} */

type GenericError = Box<dyn Error + Send + Sync + 'static>;
type GenericResult<T> = Result<T, GenericError>;

/// Read integers from a text file
/// the file should have one number on each line
fn read_numbers(file: &mut dyn BufRead) -> GenericResult<Vec<usize>> {
    let mut numbers = Vec::new();
    for line_result in file.lines() {
        let line = line_result?;
        numbers.push(line.parse()?);
    }

    Ok(numbers)
}

/* fn test_specific_error() {
    loop {
        match compile_project() {
            Ok(()) => return Ok(()),
            Err(err) => {
                if let Some(mse) = err.downcast_ref::<MissingSemicolonError>() {
                    insert_semicolon_in_source_code(mse.file(), mse.line())?;
                    continue;
                }
                return Err(err);
            }
        }
    }
} */

// custom error type
#[derive(Debug, Clone)]
pub struct JsonError {
    pub message: String,
    pub line: usize,
    pub col: usize,
}
// this much could work just fine, but we'll show all bare minimum things necessary for the
// custom error to behave like Error in rust

// Errors should be printable
impl fmt::Display for JsonError {
    fn fmt(&self, f: &mut fmt::Formatter<'_>) -> Result<(), fmt::Error> {
        write!(f, "{} ({}:{})", self.message, self.line, self.col)
    }
}

// Errors should implement the std::error::Error trait
// but the default definitions for the Error methods are fine
impl std::error::Error for JsonError { }

use thiserror::Error;

#[derive(Error, Debug)]
#[error("{message:} ({line:}, {col:})")]
pub struct JustAnotherJsonError {
    pub message: String,
    pub line: usize,
    pub col: usize,
}

fn main() -> Result<(),  Box<dyn Error>> {
// fn main() -> Result<(), JsonError> {  // will work (whether you have JsonError as std::err::Error
                                      // or not
                                      // Also works because, any (error)type can work here, which
                                      // can be printed with {:?}
    println!("Hello, world!");

    /* let io_error = io::Error::new(io::ErrorKind::Other, "timed out");
    return Err(GenericError::from(io_error)); */

    /* return Err(JsonError {
        message: "expected ] at end of array".to_string(),
        line: 10,
        col: 20,
    }); */
    return Err(Box::new(JustAnotherJsonError {
        message: "expected ] at end of array".to_string(),
        line: 10,
        col: 20,
    }));
}
