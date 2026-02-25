

type DoubleHashItem struct {
	key     int
	value   int
	deleted bool
}

type DoubleHashing struct {
	capacity int
	size     int
	table    []*DoubleHashItem
	prime    int
}

func NewDoubleHashing(cap, prime int) *DoubleHashing {
	return &DoubleHashing{
		capacity: cap,
		size:     0,
		table:    make([]*DoubleHashItem, cap),
		prime:    prime,
	}
}

func (dh *DoubleHashing) hash1(key int) int {
	return (key%dh.capacity + dh.capacity) % dh.capacity
}

func (dh *DoubleHashing) hash2(key int) int {
	return dh.prime - ((key%dh.prime + dh.prime) % dh.prime)
}

func (dh *DoubleHashing) Insert(key, value int) {
	if dh.size == dh.capacity {
		return
	}
	index := dh.hash1(key)
	step := dh.hash2(key)

	for dh.table[index] != nil && !dh.table[index].deleted && dh.table[index].key != key {
		index = (index + step) % dh.capacity
	}

	if dh.table[index] == nil || dh.table[index].deleted {
		dh.size++
	}
	dh.table[index] = &DoubleHashItem{key: key, value: value, deleted: false}
}

func (dh *DoubleHashing) Search(key int) (int, bool) {
	index := dh.hash1(key)
	step := dh.hash2(key)
	startIndex := index

	for dh.table[index] != nil {
		if !dh.table[index].deleted && dh.table[index].key == key {
			return dh.table[index].value, true
		}
		index = (index + step) % dh.capacity
		if index == startIndex {
			break
		}
	}
	return -1, false
}

func (dh *DoubleHashing) Remove(key int) {
	index := dh.hash1(key)
	step := dh.hash2(key)
	startIndex := index

	for dh.table[index] != nil {
		if !dh.table[index].deleted && dh.table[index].key == key {
			dh.table[index].deleted = true
			dh.size--
			return
		}
		index = (index + step) % dh.capacity
		if index == startIndex {
			break
		}
	}
}
