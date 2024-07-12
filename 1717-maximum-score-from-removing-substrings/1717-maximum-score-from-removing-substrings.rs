impl Solution {
    pub fn maximum_gain(mut s: String, x: i32, y: i32) -> i32 {
        let (max, min, maximizeStringFirst, maximizeStringSecond, minimizeStringFirst, minimizeStringSecond) = if x > y {
            (x, y, 'a', 'b', 'b', 'a')
        } else {
            (y, x, 'b', 'a', 'a', 'b')
        };
        let mut stack: Vec<char> = Vec::new();
        let mut res = 0;
        for ch in s.chars() {
            let last = (stack.len() - 1) as i32;
            if last >= 0 && stack[last as usize] == maximizeStringFirst && ch == maximizeStringSecond {
                res += max;
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        s = stack.iter().collect();
        stack.clear();
        for ch in s.chars() {
            let last = (stack.len() - 1) as i32;
            if last >= 0 && stack[last as usize] == minimizeStringFirst && ch == minimizeStringSecond {
                res += min;
                stack.pop();
            } else {
                stack.push(ch);
            }
        }
        res
    }
}