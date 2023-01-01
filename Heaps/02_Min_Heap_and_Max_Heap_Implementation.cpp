// Binary Heap Operations
// Link - https://practice.geeksforgeeks.org/problems/operations-on-binary-min-heap/1



int MinHeap::extractMin() {
	if (heap_size <= 0) return -1;

	int _min = harr[0];
	swap(harr[0], harr[heap_size - 1]);
	heap_size--;

	MinHeapify(0);

	return _min;
}

void MinHeap::deleteKey(int i) {
	if (heap_size <= i) return;
	decreaseKey(i, INT_MIN);
	extractMin();
}

void MinHeap::insertKey(int k) {
	if (heap_size == capacity) return;

	decreaseKey(heap_size++, k);
}


void MinHeap::decreaseKey(int i, int new_val) {
	harr[i] = new_val;
	while (i != 0 && harr[parent(i)] > harr[i]) {
		swap(harr[i], harr[parent(i)]);
		i = parent(i);
	}
}

void MinHeap::MinHeapify(int i) {
	int l = left(i);
	int r = right(i);
	int smallest = i;
	if (l < heap_size && harr[l] < harr[i]) smallest = l;
	if (r < heap_size && harr[r] < harr[smallest]) smallest = r;
	if (smallest != i) {
		swap(harr[i], harr[smallest]);
		MinHeapify(smallest);
	}
}