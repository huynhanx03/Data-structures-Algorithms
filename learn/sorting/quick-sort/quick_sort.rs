pub struct QuickSort;

impl QuickSort {
    pub fn sort(arr: &mut [i32]) {
        let n = arr.len();
        if n > 0 {
            Self::quick_sort(arr, 0, (n - 1) as isize);
        }
    }

    fn quick_sort(arr: &mut [i32], low: isize, high: isize) {
        if low < high {
            let pi = Self::partition(arr, low, high);
            Self::quick_sort(arr, low, pi - 1);
            Self::quick_sort(arr, pi + 1, high);
        }
    }

    fn partition(arr: &mut [i32], low: isize, high: isize) -> isize {
        let pivot = arr[high as usize];
        let mut i = low - 1;

        for j in low..high {
            if arr[j as usize] < pivot {
                i += 1;
                arr.swap(i as usize, j as usize);
            }
        }
        arr.swap((i + 1) as usize, high as usize);
        i + 1
    }
}
