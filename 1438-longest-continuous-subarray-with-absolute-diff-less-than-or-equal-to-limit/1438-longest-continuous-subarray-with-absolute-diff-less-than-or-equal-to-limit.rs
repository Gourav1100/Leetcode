impl Solution {
    pub fn longest_subarray(mut nums: Vec<i32>, limit: i32) -> i32 {
        use std::collections::BTreeMap;
        use std::cmp;
        nums.push(nums[nums.len() - 1]);
        let mut freq: BTreeMap<i32, i32> = BTreeMap::new();
        freq.insert(nums[0], 1);
        let mut res = 0;
        let mut back: usize = 0;
        let mut max_so_far = -1;
        let mut min_so_far = -1;
        let mut front: usize = 1;
        for _ in 1..nums.len() {
            if let Some(mut entry) = freq.first_entry() {
                min_so_far = *entry.key();
            }
            if let Some(mut entry) = freq.last_entry() {
                max_so_far = *entry.key();
            }
            if (max_so_far - min_so_far) > limit {
                res = cmp::max(res, (front - back - 1) as i32);
                while (max_so_far - min_so_far) > limit {
                    freq.insert(nums[back], freq[&nums[back]] - 1);
                    if freq[&nums[back]] == 0 {
                        freq.remove(&nums[back]);
                    }
                    if let Some(mut entry) = freq.first_entry() {
                        min_so_far = *entry.key();
                    }
                    if let Some(mut entry) = freq.last_entry() {
                        max_so_far = *entry.key();
                    }
                    back += 1;
                }
            }
            if freq.contains_key(&nums[front]) {
                freq.insert(nums[front], freq[&nums[front]] + 1);
            } else {
                freq.insert(nums[front], 1);
            }
            front += 1;
        }
        res = cmp::max(res, (front - back - 1) as i32);
        res
    }
}