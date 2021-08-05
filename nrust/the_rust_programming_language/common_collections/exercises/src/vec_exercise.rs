pub use std::io;

fn take_input() -> Vec<i32> {
    let mut input = String::new();

    io::stdin()
        .read_line(&mut input)
        .expect("Failed to take input");

    let user_sz: usize;
    loop {
        user_sz = match input.trim().parse() {
            Ok(num) => num,
            Err(_) => continue
        };
        break;
    }
    let mut v: Vec<i32> = Vec::with_capacity(user_sz);

    for _ in 0..user_sz {
        let mut val = String::new();
        io::stdin()
            .read_line(&mut val)
            .expect("Failed to read value");
        let num: i32 = match val.trim().parse() {
            Ok(num) => num,
            Err(_) => panic!("Can't get the value"),
        };
        v.push(num);
    }

    v
}

fn get_mean(vec: &Vec<i32>) -> i32 {
    let mut sum: i32 = 0;
    for i in vec {
        sum += *i;
    }
    return sum / vec.len() as i32;
}

fn get_median(vec: &mut Vec<i32>) -> i32 {
    if 0 == vec.len() { return 0; }
    let vsize: usize = vec.len();
    vec.sort();
    if 0 == vsize % 2 {
        return (vec[vsize / 2 - 1] + vec[vsize / 2]) / 2;
    }
    else {
        return vec[vsize / 2];
    }
}

fn get_mode(vec: &Vec<i32>) -> i32 {
    use std::collections::HashMap;
    let mut hmap: HashMap<i32, u32> = HashMap::new();
    for num in vec {
        let count = hmap.entry(*num).or_insert(0);
        *count += 1;
    }
    let (mut mk, mut mv): (i32, u32) = (0, u32::MIN);
    for (k, v) in hmap.iter() {
        if v > &mv {
            mv = *v;
            mk = *k;
        }
    }
    mk
}

pub fn vec_ques_operations() {
    let mut vec = take_input();
    let mean = get_mean(&vec);
    println!("mean is: {}", mean);
    let median = get_median(&mut vec);
    println!("median is: {}", median);
    let mode = get_mode(&vec);
    println!("mode is: {}", mode);
}
