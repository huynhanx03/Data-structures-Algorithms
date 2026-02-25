pub struct RollingHash {
    base: i64,
    modulus: i64,
}

impl RollingHash {
    pub fn new(base: i64, modulus: i64) -> Self {
        RollingHash { base, modulus }
    }

    pub fn compute_hash(&self, s: &str) -> i64 {
        let mut hash_value: i64 = 0;
        for ch in s.chars() {
            hash_value = (hash_value * self.base + ch as i64) % self.modulus;
        }
        hash_value
    }

    pub fn rabin_karp_search(&self, text: &str, pattern: &str) -> Vec<usize> {
        let n = text.len();
        let m = pattern.len();
        let mut result = Vec::new();

        if m == 0 || m > n {
            return result;
        }

        let text_bytes = text.as_bytes();
        let pattern_bytes = pattern.as_bytes();

        let mut pattern_hash: i64 = 0;
        let mut current_hash: i64 = 0;
        let mut h: i64 = 1;

        for _ in 0..(m - 1) {
            h = (h * self.base) % self.modulus;
        }

        for i in 0..m {
            pattern_hash = (pattern_hash * self.base + pattern_bytes[i] as i64) % self.modulus;
            current_hash = (current_hash * self.base + text_bytes[i] as i64) % self.modulus;
        }

        for i in 0..=(n - m) {
            if pattern_hash == current_hash {
                let mut match_found = true;
                for j in 0..m {
                    if text_bytes[i + j] != pattern_bytes[j] {
                        match_found = false;
                        break;
                    }
                }
                if match_found {
                    result.push(i);
                }
            }
            if i < n - m {
                current_hash = (text_bytes[i + m] as i64
                    + self.base * (current_hash - (text_bytes[i] as i64) * h) % self.modulus)
                    % self.modulus;
                if current_hash < 0 {
                    current_hash += self.modulus;
                }
            }
        }
        result
    }
}
