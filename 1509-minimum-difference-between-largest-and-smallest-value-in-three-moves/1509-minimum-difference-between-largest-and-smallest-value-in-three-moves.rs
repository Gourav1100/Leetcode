impl Solution {
    pub fn min_difference(mut nums: Vec<i32>) -> i32 {
        use std::cmp;
        nums.sort();
        let mut res = nums[nums.len() - 1] - nums[0];
        for i in 0..4 {
            let start = cmp::min(i as i32, (nums.len() - 1) as i32) as usize;
            let end = cmp::max(0, (nums.len() as i32) - 4 + (i as i32)) as usize;
            res = cmp::min(res, (nums[start] - nums[end]).abs());
        }
        res
    }
}