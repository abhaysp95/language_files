use std::env;
use std::process;

use minigrep::Config;
// We add 'use minigrep::Config' line to bring the 'Config' type from the library crate into the binary crate's scope

fn main() {
    //let args: Vec<String> = env::args().collect();

    //let config = Config::new(&args).unwrap_or_else(|err| {
        //eprintln!("Problem parsing arguments: {}", err);
        //process::exit(1);
    //});

    let config = Config::new(env::args()).unwrap_or_else(|err| {
        eprintln!("Problem parsing arguments: {}", err);
        process::exit(1);
    });

    if let Err(e) = minigrep::run(config) {
        eprintln!("Application error: {}", e);
        process::exit(1);
    }  // since we'll not get any return on success from run(), we used 'if let' instead of 'unwrap_or_else'
}

