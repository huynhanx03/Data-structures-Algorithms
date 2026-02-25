use std::cmp::Ordering;

pub struct BinarySearch;

impl BinarySearch {
    pub fn search(arr: &[i32], target: i32) -> Option<usize> {
        if arr.is_empty() {
            return None;
        }

        let mut left = 0;
        let mut right = arr.len() - 1;

        while left <= right {
            let mid = left + (right - left) / 2;

            match arr[mid].cmp(&target) {
                Ordering::Equal => return Some(mid),
                Ordering::Less => left = mid + 1,
                Ordering::Greater => {
                    if mid == 0 {
                        break;
                    }
                    right = mid - 1;
                }
            }
        }
        None
    }
}
