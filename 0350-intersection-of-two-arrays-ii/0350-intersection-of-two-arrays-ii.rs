impl Solution {
    pub fn intersect(nums1: Vec<i32>, nums2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;
        use std::cmp;
        let mut freq_a: HashMap<i32, i32> = HashMap::new();
        let mut freq_b: HashMap<i32, i32> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();
        for num in nums1 {
            *freq_a.entry(num.to_owned()).or_default() += 1;
        }
        for num in nums2 {
            *freq_b.entry(num.to_owned()).or_default() += 1;
        }
        for (key, value) in freq_a {
            if let Some(value_b) = freq_b.get(&key.to_owned()) {
                for _ in 0..cmp::min(value, *value_b) {
                    result.push(key.to_owned());
                }
            }
        }
        result
    }
}