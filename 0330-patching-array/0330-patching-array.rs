impl Solution {
    pub fn min_patches(nums: Vec<i32>, n: i32) -> i32 {
        let mut index = 0;
        let mut patches = 0;
        let mut sum: i64 = 0;
        while index < nums.len() && sum < (n as i64) {
            if sum >= (nums[index] as i64) || (nums[index] as i64) == sum + 1 {
                sum += nums[index] as i64;
                index += 1;
            } else {
                sum += sum + 1;             
                patches += 1;
            }
        }
        while sum < (n as i64) {
            sum += sum + 1;
            patches += 1;
        }
        patches
    }
}