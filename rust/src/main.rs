mod nth_node_from_end;
use nth_node_from_end::Solution as Sol;

fn main() {
    let list = Sol::create_list(10);
    println!("List: {list:?}");
    let res = Sol::remove_nth_from_end(list, 4) ;
    println!("Result: {res:?}");
    println!("Hello, world!");
}
