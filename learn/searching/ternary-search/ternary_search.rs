use std::cmp::Ordering;

pub struct TernarySearch;

impl TernarySearch {
    pub fn search(arr: &[i32], target: i32) -> Option<usize> {
        if arr.is_empty() {
            return None;
        }

        let mut left = 0;
        let mut right = arr.len() - 1;

        while left <= right {
            let mid1 = left + (right - left) / 3;
            let mid2 = right - (right - left) / 3;

            if arr[mid1] == target {
                return Some(mid1);
            }
            if arr[mid2] == target {
                return Some(mid2);
            }

            match target.cmp(&arr[mid1]) {
                Ordering::Less => {
                    if mid1 == 0 {
                        break;
                    }
                    right = mid1 - 1;
                }
                Ordering::Greater => match target.cmp(&arr[mid2]) {
                    Ordering::Greater => left = mid2 + 1,
                    _ => {
                        left = mid1 + 1;
                        if mid2 == 0 {
                            break;
                        }
                        right = mid2 - 1;
                    }
                },
                _ => break,
            }
        }
        None
    }
}
