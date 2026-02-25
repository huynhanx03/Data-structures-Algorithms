

type HashNode struct {
	key   int
	value int
	next  *HashNode
}

type HashTableChaining struct {
	capacity int
	table    []*HashNode
}

func NewHashTableChaining(size int) *HashTableChaining {
	return &HashTableChaining{
		capacity: size,
		table:    make([]*HashNode, size),
	}
}

func (ht *HashTableChaining) hashFunction(key int) int {
	return (key%ht.capacity + ht.capacity) % ht.capacity
}

func (ht *HashTableChaining) Insert(key, value int) {
	index := ht.hashFunction(key)
	newNode := &HashNode{key: key, value: value}

	if ht.table[index] == nil {
		ht.table[index] = newNode
	} else {
		temp := ht.table[index]
		for temp.next != nil {
			if temp.key == key {
				temp.value = value
				return
			}
			temp = temp.next
		}
		if temp.key == key {
			temp.value = value
			return
		}
		temp.next = newNode
	}
}

func (ht *HashTableChaining) Search(key int) (int, bool) {
	index := ht.hashFunction(key)
	temp := ht.table[index]

	for temp != nil {
		if temp.key == key {
			return temp.value, true
		}
		temp = temp.next
	}
	return -1, false
}

func (ht *HashTableChaining) Remove(key int) {
	index := ht.hashFunction(key)
	temp := ht.table[index]
	var prev *HashNode

	for temp != nil && temp.key != key {
		prev = temp
		temp = temp.next
	}

	if temp == nil {
		return
	}

	if prev == nil {
		ht.table[index] = temp.next
	} else {
		prev.next = temp.next
	}
}
