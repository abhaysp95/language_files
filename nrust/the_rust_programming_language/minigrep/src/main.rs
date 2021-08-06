use std::env;
use std::process;

use minigrep::Config;
// We add 'use minigrep::Config' line to bring the 'Config' type from the library crate into the binary crate's scope

fn main() {
    let args: Vec<String> = env::args().collect();

    // std::env::args will panic if any argument contains invalid Unicode, for that use std::env::args_os instead, which returns an iterator that produced OsString values instead of String values.

    // unwrap_or_else, is defined on Result<T, E> by std library
    // If the Result is an Ok value, this returns the inner value Ok is wrapping(similar to behavior of 'unwrap'). However, if the value is an 'Err' value, this method calls the code in the closure, which is an anonymous function we define and pass as an argument to 'unwrap_or_else'
    let config = Config::new(&args).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep::run(config) {
        eprintln!("Application error: {}", e);
        process::exit(1);
    }  // since we'll not get any return on success from run(), we used 'if let' instead of 'unwrap_or_else'
}

