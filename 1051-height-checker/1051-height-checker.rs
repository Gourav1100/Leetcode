impl Solution {
    pub fn height_checker(heights: Vec<i32>) -> i32 {
        let mut heights_2 = heights.clone();
        let mut result = 0;
        heights_2.sort();
        for index in 0..heights.len() {
            if heights[index] != heights_2[index] {
                result += 1;
            }
        }
        result
    }
}