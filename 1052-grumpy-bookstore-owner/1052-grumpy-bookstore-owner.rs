impl Solution {
    pub fn max_satisfied(customers: Vec<i32>, grumpy: Vec<i32>, minutes: i32) -> i32 {
        use std::cmp;
        let mut res = 0;
        for index in 0..customers.len() {
            res += if grumpy[index] == 0 {customers[index]} else {0};
        }
        let mut current = res;
        let mut tail = -minutes;
        for head in 0..customers.len() {
            current += if grumpy[head] == 1 {customers[head]} else {0};
            current -= if tail >= 0 && grumpy[tail as usize] == 1 {customers[tail as usize]} else {0};
            tail += 1;
            res = cmp::max(res, current);
        }
        res
    }
}