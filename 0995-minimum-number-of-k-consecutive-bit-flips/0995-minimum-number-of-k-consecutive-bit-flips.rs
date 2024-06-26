impl Solution {
    pub fn min_k_bit_flips(mut nums: Vec<i32>, k: i32) -> i32 {
        let mut tail = 0;
        let mut res = 0;
        let n = nums.len() as i32;
        while tail + k - 1 < n {
            if nums[tail as usize] == 0 {
                for i in (tail as usize)..((tail + k) as usize) {
                    nums[i] = 1 - nums[i];
                }
                res += 1;
            }
            tail += 1;
        }
        while tail < n {
            if nums[tail as usize] == 0 {
                return -1;
            }
            tail += 1;
        }
        res
    }
}