

type RollingHash struct {
	base int64
	mod  int64
}

func NewRollingHash(base, mod int64) *RollingHash {
	return &RollingHash{base: base, mod: mod}
}

func (rh *RollingHash) ComputeHash(s string) int64 {
	var hashValue int64 = 0
	for _, ch := range s {
		hashValue = (hashValue*rh.base + int64(ch)) % rh.mod
	}
	return hashValue
}

func (rh *RollingHash) RabinKarpSearch(text, pattern string) []int {
	n := len(text)
	m := len(pattern)
	var result []int

	if m == 0 || m > n {
		return result
	}

	var patternHash int64 = 0
	var currentHash int64 = 0
	var h int64 = 1

	for i := 0; i < m-1; i++ {
		h = (h * rh.base) % rh.mod
	}

	for i := 0; i < m; i++ {
		patternHash = (patternHash*rh.base + int64(pattern[i])) % rh.mod
		currentHash = (currentHash*rh.base + int64(text[i])) % rh.mod
	}

	for i := 0; i <= n-m; i++ {
		if patternHash == currentHash {
			match := true
			for j := 0; j < m; j++ {
				if text[i+j] != pattern[j] {
					match = false
					break
				}
			}
			if match {
				result = append(result, i)
			}
		}
		if i < n-m {
			currentHash = (int64(text[i+m]) + rh.base*(currentHash-int64(text[i])*h)%rh.mod) % rh.mod
			if currentHash < 0 {
				currentHash += rh.mod
			}
		}
	}
	return result
}
