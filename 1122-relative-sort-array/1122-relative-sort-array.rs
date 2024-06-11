impl Solution {
    pub fn relative_sort_array(arr1: Vec<i32>, arr2: Vec<i32>) -> Vec<i32> {
        use std::collections::HashMap;
        let mut hash_map: HashMap<i32, i32> = HashMap::new();
        let mut result: Vec<i32> = Vec::new();
        for num in arr1 {
            if !hash_map.contains_key(&num) {
                hash_map.insert(num, 1);
            } else if let Some(value) = hash_map.get(&num) {
                hash_map.insert(num, value + 1);
            }
        }
        for num in arr2 {
            if let Some(value) = hash_map.get(&num) {
                for i in 0..*value {
                    result.push(num);  
                }   
                hash_map.remove(&num);
            }
        }
        let mut keys = hash_map.keys().clone().collect::<Vec<&i32>>();
        keys.sort();
        for remaining_key in keys {
            if let Some(value) = hash_map.get(remaining_key) {
                for i in 0..*value {
                    result.push(*remaining_key);  
                }   
            }
        }
        result
    }
}