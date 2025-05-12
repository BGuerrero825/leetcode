use std::cmp;

pub struct Solution {}

impl Solution {
    pub fn max_area(height: Vec<i32>) -> i32 {
        let mut left = 0;
        let mut max = 0;
        let mut left_cutoff = 0;
        while left < height.len() - 1 {
            if height[left] <= left_cutoff {
                left += 1;
                continue;
            } else {
                left_cutoff = height[left];
            }
            let mut right = height.len() - 1;
            let mut right_cutoff = 0;
            while right > left {
                if height[right] <= right_cutoff {
                    right -= 1;
                    continue;
                }
                let area = cmp::min(height[left], height[right]) * ((right-left) as i32);
                if area > max {
                    max = area;
                    right_cutoff = height[right]

                }
                //println!("{i:?}, {j:?}, {area:?}");
                right -= 1;
            }
            left += 1;
        }
        max
    }
}