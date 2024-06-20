impl Solution {
    pub fn max_distance(mut position: Vec<i32>, m: i32) -> i32 {
        position.sort();
        let mut front = 0;
        let mut end = 1000000000;
        while front <= end {
            let mid = end - ((end - front) >> 1);
            let mut last = -mid;
            let mut count = 0;
            for index in 0..position.len() {
                if position[index] - last >= mid {
                    count += 1;
                    last = position[index];
                }
            }
            if count >= m {
                front = mid + 1;
            } else {
                end = mid - 1;
            }
        }
        // println!("{} {}", front, end);
        end
    }
}