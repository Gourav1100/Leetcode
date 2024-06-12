impl Solution {
    pub fn sort_colors(nums: &mut Vec<i32>) {
        let mut counts = vec![0, 0, 0];
        for i in 0..nums.len() {
            counts[nums[i] as usize] += 1;
        }
        let mut index = 0;
        for i in 0..3 {
            for j in 0..counts[i] as usize {
                nums[index] = i as i32;
                index += 1;
            }
        }
    }
}