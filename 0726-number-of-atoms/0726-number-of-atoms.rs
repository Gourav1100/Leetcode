use std::collections::BTreeMap;

impl Solution {
    pub fn count_of_atoms(formula: String) -> String {
        let mut elements_count_map: Vec<BTreeMap<String, i32>> = vec![BTreeMap::new()];
        let mut current_depth = 0;
        let mut current_element = "".to_string();
        let mut current_count = 0;
        let mut char_iter = formula.chars().peekable();

        while let Some(ch) = char_iter.next() {
            if ch >= 'A' && ch <= 'Z' {
                if !current_element.is_empty() {
                    if current_count == 0 {
                        current_count = 1;
                    }
                    let count_map = &mut elements_count_map[current_depth];
                    let count = count_map.entry(current_element.clone()).or_insert(0);
                    *count += current_count;
                    current_element = "".to_string();
                    current_count = 0;
                }
                current_element = ch.to_string();
            } else if ch >= 'a' && ch <= 'z' {
                current_element.push(ch);
            } else if ch >= '0' && ch <= '9' {
                let mut num_str = ch.to_string();
                while let Some(&next_ch) = char_iter.peek() {
                    if next_ch.is_digit(10) {
                        num_str.push(char_iter.next().unwrap());
                    } else {
                        break;
                    }
                }
                current_count = num_str.parse::<i32>().unwrap();
            } else if ch == '(' {
                if !current_element.is_empty() {
                    if current_count == 0 {
                        current_count = 1;
                    }
                    let count_map = &mut elements_count_map[current_depth];
                    let count = count_map.entry(current_element.clone()).or_insert(0);
                    *count += current_count;
                    current_element = "".to_string();
                    current_count = 0;
                }
                current_depth += 1;
                elements_count_map.push(BTreeMap::new());
            } else if ch == ')' {
                if !current_element.is_empty() {
                    if current_count == 0 {
                        current_count = 1;
                    }
                    let count_map = &mut elements_count_map[current_depth];
                    let count = count_map.entry(current_element.clone()).or_insert(0);
                    *count += current_count;
                    current_element = "".to_string();
                    current_count = 0;
                }
                let mut multiplier = 1;
                if let Some(&next_ch) = char_iter.peek() {
                    if next_ch.is_digit(10) {
                        let mut num_str = String::new();
                        while let Some(&next_ch) = char_iter.peek() {
                            if next_ch.is_digit(10) {
                                num_str.push(char_iter.next().unwrap());
                            } else {
                                break;
                            }
                        }
                        multiplier = num_str.parse::<i32>().unwrap();
                    }
                }

                let mut temp_map = BTreeMap::new();
                for (key, value) in elements_count_map[current_depth].iter() {
                    let count = value * multiplier;
                    let entry = temp_map.entry(key.clone()).or_insert(0);
                    *entry += count;
                }

                elements_count_map.pop();
                current_depth -= 1;

                for (key, value) in temp_map {
                    let count_map = &mut elements_count_map[current_depth];
                    let count = count_map.entry(key).or_insert(0);
                    *count += value;
                }
            }
        }

        if !current_element.is_empty() {
            if current_count == 0 {
                current_count = 1;
            }
            let count_map = &mut elements_count_map[current_depth];
            let count = count_map.entry(current_element.clone()).or_insert(0);
            *count += current_count;
        }

        let mut result = String::new();
        for (key, value) in elements_count_map[0].iter() {
            result.push_str(key);
            if *value > 1 {
                result.push_str(&value.to_string());
            }
        }
        result
    }
}
