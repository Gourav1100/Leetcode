impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        if time % (2 * (n - 1)) > n - 1 {2 * n - (time % (2 * (n - 1))) - 1} else {(time % (2 * (n - 1))) + 1}
    }
}