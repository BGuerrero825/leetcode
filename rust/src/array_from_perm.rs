pub struct Solution {}

impl Solution {
    pub fn build_array(nums: Vec<i32>) -> Vec<i32> {
        let mut res = Vec::new();
        for n in &nums {
            res.push(nums[*n as usize]);
        }
        res
    }
}