impl Solution {
    pub fn maximum_importance(n: i32, roads: Vec<Vec<i32>>) -> i64 {
        use std::collections::{HashMap, BTreeMap};
        let mut degrees: HashMap<i32, i64> = HashMap::new();
        for road in roads.clone() {
            degrees.entry(road[0]).and_modify(|e| *e += 1).or_insert(1);
            degrees.entry(road[1]).and_modify(|e| *e += 1).or_insert(1);
        }
        let mut rev: BTreeMap<i64, Vec<i32>> = BTreeMap::new();
        for (key, value) in degrees.clone().into_iter() {
            rev.entry(value).or_insert_with(Vec::new).push(key);
        }
        let mut current = n as i64;
        let mut res: i64 = 0;
        for (key, values) in rev.iter().rev() {
            for value in values {
                degrees.insert(*value, current);
                current -= 1;
            }
        }
        for road in roads {
            if let (Some(a), Some(b)) = (degrees.get(&road[0]), degrees.get(&road[1])) {
                res += a + b;
            }
        }
        res
    }
}