use std::cmp::Ordering;

#[derive(Clone, Eq, PartialEq)]
pub struct BigInt {
    digits: Vec<i32>,
    base: i32,
}

impl BigInt {
    pub fn new() -> Self {
        BigInt {
            digits: Vec::new(),
            base: 1_000_000_000,
        }
    }

    pub fn from_i64(mut v: i64) -> Self {
        let mut bi = BigInt::new();
        if v == 0 {
            bi.digits.push(0);
        }
        let base_i64 = bi.base as i64;
        while v > 0 {
            bi.digits.push((v % base_i64) as i32);
            v /= base_i64;
        }
        bi
    }

    pub fn from_string(mut s: String) -> Self {
        let mut bi = BigInt::new();
        if s.is_empty() {
            bi.digits.push(0);
            return bi;
        }
        while s.len() % 9 != 0 {
            s.insert(0, '0');
        }
        for i in (0..s.len()).step_by(9) {
            let v = s[i..i + 9].parse::<i32>().unwrap_or(0);
            bi.digits.insert(0, v);
        }
        bi.remove_leading_zeros();
        bi
    }

    fn remove_leading_zeros(&mut self) {
        while self.digits.len() > 1 && *self.digits.last().unwrap() == 0 {
            self.digits.pop();
        }
    }

    pub fn add(&self, other: &Self) -> Self {
        let mut res = BigInt::new();
        let mut carry = 0;
        let mut i = 0;

        while i < self.digits.len() || i < other.digits.len() || carry > 0 {
            if i < self.digits.len() {
                carry += self.digits[i];
            }
            if i < other.digits.len() {
                carry += other.digits[i];
            }
            res.digits.push(carry % self.base);
            carry /= self.base;
            i += 1;
        }
        res.remove_leading_zeros();
        res
    }
}

impl PartialOrd for BigInt {
    fn partial_cmp(&self, other: &Self) -> Option<Ordering> {
        Some(self.cmp(other))
    }
}

impl Ord for BigInt {
    fn cmp(&self, other: &Self) -> Ordering {
        if self.digits.len() != other.digits.len() {
            return self.digits.len().cmp(&other.digits.len());
        }
        for i in (0..self.digits.len()).rev() {
            if self.digits[i] != other.digits[i] {
                return self.digits[i].cmp(&other.digits[i]);
            }
        }
        Ordering::Equal
    }
}
