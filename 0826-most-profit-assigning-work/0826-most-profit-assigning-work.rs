use std::cmp::Ordering;
#[derive(Debug)]
struct Job {
    profit: i32,
    difficulty: i32,
}
impl Job {
    pub fn new(profit: i32, difficulty: i32) -> Self {
        Self {
            profit: profit,
            difficulty: difficulty
        }
    }
}
impl Solution {
    pub fn max_profit_assignment(difficulty: Vec<i32>, profit: Vec<i32>, mut worker: Vec<i32>) -> i32 {
        let size: usize = profit.len();
        let mut arr: Vec<Job> = Vec::new();
        let mut result = 0;
        let mut pointer_worker: i32 = (worker.len() - 1) as i32;
        let mut pointer_job: i32 = 0;
        worker.sort();
        for index in 0..size {
            arr.push(Job::new(profit[index], difficulty[index]));
        }
        arr.sort_by(|job_a: &Job, job_b: &Job| {
            job_b.profit.cmp(&job_a.profit).then(job_b.difficulty.cmp(&job_a.difficulty))
        });
        while pointer_worker >= 0 && pointer_job < (arr.len() as i32) {
            if arr[pointer_job as usize].difficulty > worker[pointer_worker as usize] {
                pointer_job += 1;
            } else {
                result += arr[pointer_job as usize].profit;
                pointer_worker -= 1;
            }
        }
        result
    }
}