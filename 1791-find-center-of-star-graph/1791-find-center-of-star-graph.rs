impl Solution {
    pub fn find_center(edges: Vec<Vec<i32>>) -> i32 {
        use std::cmp;
        use std::collections::HashMap;
        let mut freq: HashMap<i32, i32> = HashMap::new();
        let mut res = -1;
        let mut res_freq = 0;
        for edge in edges {
            if freq.contains_key(&edge[0]) {
                freq.insert(edge[0], freq[&edge[0]] + 1);
            } else {
                freq.insert(edge[0], 1);
            }
            if freq.contains_key(&edge[1]) {
                freq.insert(edge[1], freq[&edge[1]] + 1);
            } else {
                freq.insert(edge[1], 1);
            }
            res = if freq[&edge[0]] > res_freq {edge[0]} else {res};
            res_freq = cmp::max(res_freq, freq[&edge[0]]);
            res = if freq[&edge[1]] > res_freq {edge[1]} else {res};
            res_freq = cmp::max(res_freq, freq[&edge[1]]);
        }
        res
    }
}