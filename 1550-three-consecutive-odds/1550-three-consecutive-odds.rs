impl Solution {
    pub fn three_consecutive_odds(mut arr: Vec<i32>) -> bool {
        for index in 0..arr.len() {
            arr[index] = (arr[index] % 2) as i32;
            arr[index] += (arr[index] * (if index > 0 {arr[index - 1]} else {0}));
            if arr[index] == 3 {
                return true;
            }
        }
        return false;
    }
}