impl Solution {
    pub fn num_water_bottles(num_bottles: i32, num_exchange: i32) -> i32 {
        let mut res = num_bottles;
        let mut empty = num_bottles;
        while empty >= num_exchange {
            res += empty / num_exchange;
            empty = (empty / num_exchange) + (empty % num_exchange);
        }
        res
    }
}