pub struct MergeSort;

impl MergeSort {
    pub fn sort(arr: &mut [i32]) {
        let n = arr.len();
        if n > 0 {
            Self::merge_sort(arr, 0, n - 1);
        }
    }

    fn merge_sort(arr: &mut [i32], left: usize, right: usize) {
        if left < right {
            let mid = left + (right - left) / 2;
            Self::merge_sort(arr, left, mid);
            Self::merge_sort(arr, mid + 1, right);
            Self::merge(arr, left, mid, right);
        }
    }

    fn merge(arr: &mut [i32], left: usize, mid: usize, right: usize) {
        let n1 = mid - left + 1;
        let n2 = right - mid;

        let mut l = Vec::with_capacity(n1);
        let mut r = Vec::with_capacity(n2);

        for i in 0..n1 {
            l.push(arr[left + i]);
        }
        for j in 0..n2 {
            r.push(arr[mid + 1 + j]);
        }

        let mut i = 0;
        let mut j = 0;
        let mut k = left;

        while i < n1 && j < n2 {
            if l[i] <= r[j] {
                arr[k] = l[i];
                i += 1;
            } else {
                arr[k] = r[j];
                j += 1;
            }
            k += 1;
        }

        while i < n1 {
            arr[k] = l[i];
            i += 1;
            k += 1;
        }
        while j < n2 {
            arr[k] = r[j];
            j += 1;
            k += 1;
        }
    }
}
