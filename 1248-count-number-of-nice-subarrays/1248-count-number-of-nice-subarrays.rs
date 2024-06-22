impl Solution {
    pub fn number_of_subarrays(mut nums: Vec<i32>, k: i32) -> i32 {
        nums.push(1);
        let mut back: usize = 0;
        let mut odd_count = 0;
        let mut even_count_after = 0;
        let mut even_count_before = 0;
        let mut res = 0;
        for front in 0..nums.len() {
            if nums[front] % 2 == 1 {
                odd_count += 1;
                while odd_count > k {
                    if nums[back] % 2 == 1 {
                        odd_count -= 1;
                        res += (even_count_before + 1) * (even_count_after + 1);
                    } else {
                        even_count_before += 1;
                    }
                    back += 1;
                }
                even_count_before = 0;
                even_count_after = 0;
            } else {
                even_count_after += 1;
            }
        }
        res
    }
}