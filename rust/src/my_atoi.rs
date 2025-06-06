pub struct Solution {}

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut sum: i32 = 0;
        let mut sign = 1;
        let mut found_digit = false;
        for c in s.chars() {
            if c.is_ascii_whitespace() && !found_digit {
            } else if c == '+' && !found_digit {
                found_digit = true;
            } else if c == '-' && !found_digit {
                found_digit = true;
                sign = -1;
            } else if c >= '0' && c <= '9' {
                found_digit = true;
                sum = sum
                    .saturating_mul(10)
                    .saturating_add((c.to_digit(10).unwrap()) as i32 * sign);
            } else {
                break;
            }
        }
        sum as i32
    }
}

