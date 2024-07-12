impl Solution {
    pub fn maximum_gain(mut s: String, x: i32, y: i32) -> i32 {
        let (max, min, maximizeStringFirst, maximizeStringSecond, minimizeStringFirst, minimizeStringSecond) = if x > y {
            (x, y, 'a', 'b', 'b', 'a')
        } else {
            (y, x, 'b', 'a', 'a', 'b')
        };
        let mut stack: Vec<char> = Vec::new();
        let mut res = 0;
        let mut last = -1;
        for ch in s.chars() {
            if last > -1 && stack[last as usize] == maximizeStringFirst && ch == maximizeStringSecond {
                res += max;
                stack.pop();
                last -= 1;
            } else {
                stack.push(ch);
                last += 1;
            }
        }
        s = stack.iter().collect();
        last = -1;
        stack.clear();
        for ch in s.chars() {
            if last >= 0 && stack[last as usize] == minimizeStringFirst && ch == minimizeStringSecond {
                res += min;
                stack.pop();
                last -= 1;
            } else {
                stack.push(ch);
                last += 1;
            }
        }
        res
    }
}