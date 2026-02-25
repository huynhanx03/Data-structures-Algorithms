

type HashItem struct {
	key     int
	value   int
	deleted bool
}

type HashTableLinearProbing struct {
	capacity int
	size     int
	table    []*HashItem
}

func NewHashTableLinearProbing(size int) *HashTableLinearProbing {
	return &HashTableLinearProbing{
		capacity: size,
		size:     0,
		table:    make([]*HashItem, size),
	}
}

func (ht *HashTableLinearProbing) hashFunction(key int) int {
	return (key%ht.capacity + ht.capacity) % ht.capacity
}

func (ht *HashTableLinearProbing) Insert(key, value int) {
	if ht.size == ht.capacity {
		return
	}
	index := ht.hashFunction(key)

	for ht.table[index] != nil && !ht.table[index].deleted && ht.table[index].key != key {
		index = (index + 1) % ht.capacity
	}

	if ht.table[index] == nil || ht.table[index].deleted {
		ht.size++
	}
	ht.table[index] = &HashItem{key: key, value: value, deleted: false}
}

func (ht *HashTableLinearProbing) Search(key int) (int, bool) {
	index := ht.hashFunction(key)
	startIndex := index

	for ht.table[index] != nil {
		if !ht.table[index].deleted && ht.table[index].key == key {
			return ht.table[index].value, true
		}
		index = (index + 1) % ht.capacity
		if index == startIndex {
			break
		}
	}
	return -1, false
}

func (ht *HashTableLinearProbing) Remove(key int) {
	index := ht.hashFunction(key)
	startIndex := index

	for ht.table[index] != nil {
		if !ht.table[index].deleted && ht.table[index].key == key {
			ht.table[index].deleted = true
			ht.size--
			return
		}
		index = (index + 1) % ht.capacity
		if index == startIndex {
			break
		}
	}
}
