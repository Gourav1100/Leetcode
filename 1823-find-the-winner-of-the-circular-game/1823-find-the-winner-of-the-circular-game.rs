impl Solution {
    pub fn find_the_winner(n: i32, k: i32) -> i32 {
        let mut circle: Vec<i32> = vec![0; n as usize];
        let mut last: usize = 0;
        let mut res = -1;
        for i in 0..((n - 1) as usize) {
            let mut step = k as usize;
            while step != 0 {
                if circle[last] == 0 {
                    step -= 1;
                }
                if step != 0 {
                    last = (last + 1) % (n as usize);
                }
            }
            circle[last] = 1;
        }
        for i in 0..(n as usize) {
            res = if circle[i] == 0 {(i + 1) as i32} else {res};
        }
        res
    }
}