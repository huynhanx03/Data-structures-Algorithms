pub struct DigitDP {
    s: String,
    memo: Vec<Vec<i64>>,
}

impl DigitDP {
    pub fn new() -> Self {
        DigitDP {
            s: String::new(),
            memo: Vec::new(),
        }
    }

    fn solve(&mut self, id: usize, flag: bool) -> i64 {
        if id == self.s.len() {
            return 1;
        }

        let flag_idx = if flag { 1 } else { 0 };

        if self.memo[id][flag_idx] != -1 {
            return self.memo[id][flag_idx];
        }

        let mut ans: i64 = 0;
        let limit = if flag {
            self.s.as_bytes()[id] - b'0'
        } else {
            9
        };

        for i in 0..=limit {
            let new_flag = flag && (i == limit);
            ans += self.solve(id + 1, new_flag);
        }

        self.memo[id][flag_idx] = ans;
        ans
    }

    pub fn count_valid(&mut self, target: i64) -> i64 {
        if target < 0 {
            return 0;
        }
        self.s = target.to_string();
        self.memo = vec![vec![-1; 2]; self.s.len()];
        self.solve(0, true)
    }

    pub fn count_in_range(&mut self, l: i64, r: i64) -> i64 {
        self.count_valid(r) - self.count_valid(l - 1)
    }
}
