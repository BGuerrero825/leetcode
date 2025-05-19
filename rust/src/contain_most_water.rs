use std::cmp;

pub struct Solution {}

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {

        let mut left = 0;
        let mut right = height.len() - 1;
        let mut max = 0;

        while right > left {
            let area = cmp::min(height[left], height[right]) * ((right-left) as i32);
            if area > max {
                max = area;
            }
            if height[right] > height[left] {
                let mut i = left;
                while height[left] >= height[i] && i < height.len(){
                    i = i+1;
                }
                left = i;
            } else {
                let mut i = right;
                while height[right] >= height[i] && i > 0 {
                    i = i-1;
                }
                right = i;
            }
        }
        max
    }
}