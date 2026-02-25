pub struct LinearSearch;

impl LinearSearch {
    pub fn search(arr: &[i32], target: i32) -> Option<usize> {
        arr.iter().position(|&x| x == target)
    }
}
