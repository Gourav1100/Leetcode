impl Solution {
    pub fn maximum_gain(mut s: String, x: i32, y: i32) -> i32 {
        let (max, min, maximizeString, minimizeString) = if x > y {
            (x, y, "ab".to_string(), "ba".to_string())
        } else {
            (y, x, "ba".to_string(), "ab".to_string())
        };
        let mut stack: Vec<char> = Vec::new();
        let mut res = 0;
        for ch in s.chars() {
            let last = (stack.len() - 1) as i32;
            if last >= 0 && stack[last as usize] == maximizeString.chars().nth(0).unwrap() && ch == maximizeString.chars().nth(1).unwrap() {
                res += max;
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        s = "".to_string();
        for ch in stack {
            s += ch.to_string().as_str().as_ref();
        }
        stack = Vec::new();
        for ch in s.chars() {
            let last = (stack.len() - 1) as i32;
            if last >= 0 && stack[last as usize] == minimizeString.chars().nth(0).unwrap() && ch == minimizeString.chars().nth(1).unwrap() {
                res += min;
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        res
    }
}