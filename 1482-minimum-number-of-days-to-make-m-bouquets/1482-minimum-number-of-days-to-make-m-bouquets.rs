impl Solution {
    pub fn min_days(bloom_day: Vec<i32>, m: i32, k: i32) -> i32 {
        if (bloom_day.len() as i64) < (m as i64) * (k as i64) {
            return -1;
        }
        let mut front = 0;
        let mut end = 1000000000;
        while front <= end {
            let mid = end - ((end - front) >> 1);
            let mut count = 0;
            let mut current = 0;
            let mut arr = vec![0; bloom_day.len()];
            for index in 0..bloom_day.len() {
                if (bloom_day[index] as i64) <= mid {
                    arr[index] = 1;
                }
            }
            for num in arr {
                if num != 0 {
                    current += 1;
                    if current % k == 0 {
                        count += 1;
                        current = 0;
                    }
                } else {
                    current = 0;
                }
            }
            count += if (current != 0 && current % k == 0) {1} else {0};
            if count >= m {
                end = mid - 1;
            } else {
                front = mid + 1;
            }
        }
        front as i32
    }
}