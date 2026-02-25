

import (
	"strconv"
)

type BigInt struct {
	digits []int
	base   int
}

func NewBigInt() *BigInt {
	return &BigInt{
		digits: make([]int, 0),
		base:   1e9,
	}
}

func NewBigIntFromInt64(v int64) *BigInt {
	bi := &BigInt{base: 1e9}
	if v == 0 {
		bi.digits = append(bi.digits, 0)
	}
	for v > 0 {
		bi.digits = append(bi.digits, int(v%int64(bi.base)))
		v /= int64(bi.base)
	}
	return bi
}

func NewBigIntFromString(s string) *BigInt {
	bi := &BigInt{base: 1e9}
	if len(s) == 0 {
		bi.digits = append(bi.digits, 0)
		return bi
	}
	for len(s)%9 != 0 {
		s = "0" + s
	}
	for i := 0; i < len(s); i += 9 {
		v, _ := strconv.Atoi(s[i : i+9])
		// prepend to digits
		bi.digits = append([]int{v}, bi.digits...)
	}
	bi.removeLeadingZeros()
	return bi
}

func (b *BigInt) removeLeadingZeros() {
	for len(b.digits) > 1 && b.digits[len(b.digits)-1] == 0 {
		b.digits = b.digits[:len(b.digits)-1]
	}
}

func (b *BigInt) Add(other *BigInt) *BigInt {
	res := NewBigInt()
	carry := 0
	maxLen := len(b.digits)
	if len(other.digits) > maxLen {
		maxLen = len(other.digits)
	}

	for i := 0; i < maxLen || carry > 0; i++ {
		if i < len(b.digits) {
			carry += b.digits[i]
		}
		if i < len(other.digits) {
			carry += other.digits[i]
		}
		res.digits = append(res.digits, carry%b.base)
		carry /= b.base
	}
	res.removeLeadingZeros()
	return res
}

func (b *BigInt) LessThan(other *BigInt) bool {
	if len(b.digits) != len(other.digits) {
		return len(b.digits) < len(other.digits)
	}
	for i := len(b.digits) - 1; i >= 0; i-- {
		if b.digits[i] != other.digits[i] {
			return b.digits[i] < other.digits[i]
		}
	}
	return false
}

func (b *BigInt) Equals(other *BigInt) bool {
	return !b.LessThan(other) && !other.LessThan(b)
}
