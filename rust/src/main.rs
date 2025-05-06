mod my_atoi;

fn main() {
    let res = my_atoi::Solution::my_atoi("42".to_string());
    println!("Result: {res:?}");
    let res = my_atoi::Solution::my_atoi("-32".to_string());
    println!("Result: {res:?}");
    let res = my_atoi::Solution::my_atoi("-91283472332".to_string());
    println!("Result: {res:?}");
    println!("Hello, world!");
}
