mod contain_most_water;

fn main() {
    let list = vec![4,1,2,5];
    let res = contain_most_water::Solution::max_area(list);
    println!("Result: {res:?}");
    println!("Hello, world!");
}
