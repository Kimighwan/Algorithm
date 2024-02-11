#include <iostream>

constexpr int size = 9;
int heap[9] = { 7,6,5,8,3,5,9,1,6 };

int main() {
	for (int i = 0; i < size; i++) { // Build Max Heap
		int c = i;
		do {
			int root = (c - 1) / 2;
			if (heap[root] < heap[c]) {
				int tmp = heap[c];
				heap[c] = heap[root];
				heap[root] = tmp;
			}
			c = root;
		} while (c != 0);
	}
	// Max value and Root value Swtiching
	for (int i = size - 1; i >= 0; i--) {
		int tmp = heap[0];
		heap[0] = heap[i];
		heap[i] = tmp;
		int root = 0;
		int c = 1;
		do { // Heapify
			c = 2 * root + 1;
			if (heap[c] < heap[c + 1] && c < i - 1) {
				c++;
			}
			if (heap[root] < heap[c] && c < i) {
				int tmp = heap[0];
				heap[0] = heap[c];
				heap[c] = tmp;
			}
			root = c;
		} while (c < i);
	}
	for (int i = 0; i < size; i++)
		std::cout << heap[i] << " ";
}