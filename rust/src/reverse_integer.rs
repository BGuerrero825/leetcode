use std::i32;

pub struct Solution {}

impl Solution {
    pub fn reverse(x: i32) -> i32 {
        let mut number: i64 = x as i64;
        let mut digits: Vec<i64> = Vec::new();
        let mut place: i64 = 1;
        while number.abs() >= place {
            let remainder: i64 = number % (place * 10);
            number -= remainder;
            digits.push(remainder / place);
            place *= 10;
        };
        let reversed: i64 = digits.iter().fold(0, |acc, dig| (acc * 10) + dig);
        if reversed > i32::MAX as i64 || reversed < i32::MIN as i64 {
            return 0;
        }
        reversed as i32
    }
}