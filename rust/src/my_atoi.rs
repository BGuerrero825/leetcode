pub struct Solution {}

impl Solution {
    pub fn my_atoi(s: String) -> i32 {
        let mut sum: i64 = 0;
        let mut sign = 1;
        let mut found_digit = false;
        for c in s.chars() {
            if c.is_ascii_whitespace() && !found_digit {
            }
            else if c == '+' && !found_digit {
                found_digit = true;
            }
            else if c == '-' && !found_digit {
                found_digit = true;
                sign = -1;
            }
            else if c >= '0' && c <= '9' {
                found_digit = true;
                sum = (sum * 10) + ((c as i64) - ('0' as i64));
                if sum > i32::MAX.into() {
                    break;
                }
            }  
            else {
                break;
            }

        }
        sum *= sign;
        if sum > i32::MAX.into() {
            return i32::MAX;
        }
        if sum < i32::MIN.into() {
            return i32::MIN;
        }
        sum as i32
    }
}