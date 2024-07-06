impl Solution {
    pub fn pass_the_pillow(n: i32, time: i32) -> i32 {
        let round_trip = 2 * (n - 1);
        let remainder = time % round_trip;
        let result = if remainder > n - 1 {2 * n - remainder - 1} else {remainder + 1};
        result
    }
}