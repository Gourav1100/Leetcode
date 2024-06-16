impl Solution {
    pub fn find_maximized_capital(k: i32, mut w: i32, profits: Vec<i32>, capital: Vec<i32>) -> i32 {
        use std::collections::BinaryHeap;
        let mut arr: Vec<_> = profits.iter().zip(capital.iter()).map(|(&p, &c)| (p, c)).collect();
        let mut index = 0;
        arr.sort_by(|a, b| {
            a.1.cmp(&b.1)
        });
        let mut heap = BinaryHeap::new();
        for _ in 0.. k {
            while index <  arr.len() && arr[index].1 <= w {
                heap.push(arr[index].0);
                index += 1;
            }
            if let Some(profit) = heap.pop() {
                w += profit
            }
        }
        w
    }
}