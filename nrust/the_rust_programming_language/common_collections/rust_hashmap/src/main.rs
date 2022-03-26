use std::collections::HashMap;

fn main() {
    let mut scores = HashMap::new();

    scores.insert(String::from("Blue"), 10);
    scores.insert(String::from("Yellow"), 50);


    let teams = vec![String::from("Blue"), String::from("Yellow")];
    let initial_scores = vec![10, 50];

    let mut scores: HashMap<_, _> = teams.into_iter().zip(
        initial_scores.into_iter()).collect();
    // the 'collect' method gathers data into a number of collection types, including HashMap
    // the type annotation 'HashMap<_, _>' is needed here because it's possible to 'collect' into many different data structures and Rust doesn't know which you want unless you specify
    // so, above the 'key' type will be 'String' and 'value' type will be 'i32'


    // Hash Maps and Ownership
    // for types that implement the 'Copy trait', like i32, the values are copied into the hash map. For owned values like 'String', the values will be moved and the hash map will be the owner of those values

    let field_name = String::from("Favorite Color");
    let field_value = String::from("Blue");

    let mut map = HashMap::new();
    map.insert(field_name, field_value);
    // field_name and field_value are invalid(moved) at this point, using them now will give error

    // if we insert references to values into the hash map, the values won't be moved into the hash map. The values that the references point to must be valid for atleast as long as the hash map is valid.


    // Accessing values in Hash Map
    let team_name = String::from("Blue");
    let _score = scores.get(&team_name);  // similar to Vector, result here will be of Option<&T>(enum) type, so we'll get Some(&10)


    // updating a hash map
    // overwriting a value
    let mut scores = HashMap::new();
    scores.insert(String::from("Blue"), 25);  // overwriting 10 with 25
    println!("{:?}", scores);

    // only inserting a value if the key has no value
    scores.entry(String::from("Yellow")).or_insert(50);
    scores.entry(String::from("Blue")).or_insert(50);
    // 'entry' API takes the key you want to check as a parameter. The return value of the 'entry' method is enum called 'Entry' that represents a value that might or might not exist

    // the 'or_insert' method on 'Entry' is defined to return a mutable reference to the value for the corresponding Entry key if that key exists, if not, inserts the parameter as the new value for this key and returns mutable reference to the new value


    // updating a value based on the old value
    let text = "hello world wonderful world";

    let mut map = HashMap::new();

    for word in text.split_whitespace() {
        let count = map.entry(word).or_insert(0);
        // or_insert method actually returns a mutable reference(&mut v) to the value for the key
        *count += 1;  // mutable reference goes out of scope after this
    }
}
