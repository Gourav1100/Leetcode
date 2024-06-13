impl Solution {
    pub fn min_moves_to_seat(mut seats: Vec<i32>, mut students: Vec<i32>) -> i32 {
        seats.sort();
        students.sort();
        let mut result = 0;
        for index in 0..seats.len() {
            result += (seats[index] - students[index]).abs();
        }
        result
    }
}