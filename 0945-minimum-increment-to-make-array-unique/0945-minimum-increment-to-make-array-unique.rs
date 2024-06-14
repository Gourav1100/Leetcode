impl Solution {
    pub fn min_increment_for_unique(mut nums: Vec<i32>) -> i32 {
        use std::collections::HashMap;
        nums.sort();
        let mut next: usize = 0;
        let mut repeated: Vec<i32> = Vec::new();
        let mut isAvailable: HashMap<i32, i32> = HashMap::new();
        let mut result: i32 = 0;
        for index in 0..nums.len() {
            isAvailable.insert(nums[index], 1);
            if index > 0 && nums[index] == nums[index - 1] {
                repeated.push(nums[index]);
            }
        }
        for index in 0..200000 {
            if next == repeated.len() {
                break;
            }
            if (index as i32) > repeated[next] && isAvailable.contains_key(&(index as i32)) == false {
                result += (index as i32) - repeated[next];
                next += 1;
            }
        }
        result
    }
}