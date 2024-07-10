impl Solution {
    pub fn min_operations(logs: Vec<String>) -> i32 {
        let mut depth = 0;
        for log in logs {
            match log.as_str() {
                "../" => {
                    depth = if depth - 1 > -1 {depth - 1} else {0};
                },
                "./" => {
                    continue;
                },
                _ => {
                    depth += 1;
                }
            }
        }
        depth
    }
}