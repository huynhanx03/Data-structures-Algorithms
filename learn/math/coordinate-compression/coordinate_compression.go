

import "sort"

type CoordinateCompression struct {
	original   []int
	compressed []int
}

func NewCoordinateCompression(v []int) *CoordinateCompression {
	cc := &CoordinateCompression{
		original:   make([]int, len(v)),
		compressed: make([]int, len(v)),
	}
	copy(cc.original, v)
	copy(cc.compressed, v)

	sort.Ints(cc.compressed)

	// Unique elements
	unique := []int{}
	if len(cc.compressed) > 0 {
		unique = append(unique, cc.compressed[0])
		for i := 1; i < len(cc.compressed); i++ {
			if cc.compressed[i] != cc.compressed[i-1] {
				unique = append(unique, cc.compressed[i])
			}
		}
	}
	cc.compressed = unique
	return cc
}

func (cc *CoordinateCompression) GetCompressedValue(val int) int {
	return sort.SearchInts(cc.compressed, val)
}

func (cc *CoordinateCompression) GetOriginalValue(compressedVal int) int {
	if compressedVal >= 0 && compressedVal < len(cc.compressed) {
		return cc.compressed[compressedVal]
	}
	return -1
}

func (cc *CoordinateCompression) CompressArray() []int {
	res := make([]int, len(cc.original))
	for i, val := range cc.original {
		res[i] = cc.GetCompressedValue(val)
	}
	return res
}
