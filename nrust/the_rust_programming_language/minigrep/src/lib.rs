use std::error::Error;
use std::fs;
use std::env;

pub struct Config {
    pub query: String,
    pub filename: String,
    pub case_sensitive: bool,
}

impl Config {
    pub fn new(args: &[String]) -> Result<Config, &str> {
        if args.len() < 3 {
            return Err("not enough arguments provided");
        }
        let query = args[1].clone();
        let filename = args[2].clone();

        // we are using 'is_err' method on the 'Result'(since env::var function returns a Result) to check whether it's an error and therefore unset, which means it should do a case-sensitive search. We don't care about the value of the environment variable, just whether it's set r unset, s we're checking 'is_err' rather than using 'unwrap, expect, or any of the other methods we've seen on 'Result'
        let case_sensitive = env::var("CASE_INSENSITIVE").is_err();
        // if CASE_INSENSITIVE env variable is set to anything, is_err will return false and the program will perform case-insensitive search

        Ok(Config { query, filename, case_sensitive })
    }
}

// Box<dyn Error> means that the functin will return a type that implements the 'Error' trait, but we don't have to specify what particular type the return value will be. This gives us flexibility to return error values that may be of different type in different error cases
pub fn run(config: Config) -> Result<(), Box<dyn Error>> {
    let contents = fs::read_to_string(config.filename)?;

    let results = if config.case_sensitive {
        search(&config.query, &contents)
    }
    else {
        search_case_insensitive(&config.query, &contents)
    };

    for line in results {
        println!("{}", line);
    }

    Ok(())
}

#[cfg(test)]
mod tests {
    use super::*;

    #[test]
    fn one_result() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.";
        assert_eq!(vec!["safe, fast, productive."],
                   search(query, contents));
    }

    #[test]
    fn case_sensitive() {
        let query = "duct";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.
Duct tape.";
        assert_eq!(vec!["safe, fast, productive."],
                   search(query, contents));
    }

    #[test]
    fn case_insensitive() {
        let query = "rUsT";
        let contents = "\
Rust:
safe, fast, productive.
Pick three.
Trust me.";
        assert_eq!(vec!["Rust:", "Trust me."],
                   search_case_insensitive(query, contents));
    }
}

pub fn search<'a>(query: &str, contents: &'a str) -> Vec<&'a str> {
    let mut results = Vec::new();

    for line in contents.lines() {
        if line.contains(query) {
            results.push(line);
        }
    }

    results
}

pub fn search_case_insensitive<'a>(
    query: &str,
    contents: &'a str,
) -> Vec<&'a str> {
    let query = query.to_lowercase();
    // query will now be a String, not string slice
    let mut results = Vec::new();

    for line in contents.lines() {
        if line.to_lowercase().contains(&query) {
            results.push(line);
        }
    }

    results
}
