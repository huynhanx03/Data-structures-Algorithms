pub struct CoordinateCompression {
    original: Vec<i32>,
    compressed: Vec<i32>,
}

impl CoordinateCompression {
    pub fn new(v: Vec<i32>) -> Self {
        let mut compressed = v.clone();
        compressed.sort_unstable();
        compressed.dedup();

        CoordinateCompression {
            original: v,
            compressed,
        }
    }

    pub fn get_compressed_value(&self, val: i32) -> usize {
        self.compressed.binary_search(&val).unwrap_or_else(|x| x)
    }

    pub fn get_original_value(&self, compressed_val: usize) -> Option<i32> {
        self.compressed.get(compressed_val).copied()
    }

    pub fn compress_array(&self) -> Vec<usize> {
        self.original
            .iter()
            .map(|&val| self.get_compressed_value(val))
            .collect()
    }
}
