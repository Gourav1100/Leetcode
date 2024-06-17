impl Solution {
    pub fn judge_square_sum(c: i32) -> bool {
        use std::collections::HashMap;
        let range = (c as f64).sqrt() as i32;
        let mut map: HashMap<i32, bool> = HashMap::new();
        for num in 0..(range + 1) {
            map.insert(num * num, true);
            if map.contains_key(&(c - num * num)) {
                return true;
            }
        }
        false
    }
}