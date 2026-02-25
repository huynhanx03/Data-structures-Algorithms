

import "strconv"

type DigitDP struct {
	s    string
	memo [][]int64
}

func NewDigitDP() *DigitDP {
	return &DigitDP{}
}

func (dp *DigitDP) solve(id int, flag bool) int64 {
	if id == len(dp.s) {
		return 1
	}

	flagIdx := 0
	if flag {
		flagIdx = 1
	}

	if dp.memo[id][flagIdx] != -1 {
		return dp.memo[id][flagIdx]
	}

	var ans int64 = 0
	limit := 9
	if flag {
		limit = int(dp.s[id] - '0')
	}

	for i := 0; i <= limit; i++ {
		newFlag := flag && (i == limit)
		ans += dp.solve(id+1, newFlag)
	}

	dp.memo[id][flagIdx] = ans
	return ans
}

func (dp *DigitDP) CountValid(target int64) int64 {
	if target < 0 {
		return 0
	}
	dp.s = strconv.FormatInt(target, 10)
	dp.memo = make([][]int64, len(dp.s))
	for i := range dp.memo {
		dp.memo[i] = []int64{-1, -1}
	}
	return dp.solve(0, true)
}

func (dp *DigitDP) CountInRange(L, R int64) int64 {
	return dp.CountValid(R) - dp.CountValid(L-1)
}
