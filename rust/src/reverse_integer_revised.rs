use std::i32;

pub struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut number: i64 = x as i64;
        let mut reversed: i64 = 0;
        while number != 0 {
            reversed *= 10;
            let digi = number % 10;
            number /= 10;
            reversed += digi;
        }
        if reversed > i32::MAX as i64 || reversed < i32::MIN as i64 {
            return 0;
        }
        reversed as i32
    }
}