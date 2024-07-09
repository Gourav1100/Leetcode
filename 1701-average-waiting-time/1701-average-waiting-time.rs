impl Solution {
    pub fn average_waiting_time(customers: Vec<Vec<i32>>) -> f64 {
        let mut wait: f64 = 0.0;
        let n = customers.len() as f64;
        let mut next_time: i32 = customers[0][0];
        for customer in customers {
            next_time = if next_time > customer[0] {next_time} else {customer[0]} + customer[1];
            wait += (next_time - customer[0]) as f64;
        }
        wait / n
    }
}