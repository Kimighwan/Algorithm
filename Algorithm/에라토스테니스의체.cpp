#include <iostream>

int a[1000001];

void PrimeNumber() {
	for (int i = 2; i < 100000; i++)
		a[i] = i;
	for (int i = 2; i < 1000001; i++) {
		if (a[i] == 0) continue;
		for (int j = i + i; j < 1000001; j += i) {
			a[j] = 0;
		}
	}
	for (int i = 2; i < 1000001; i++)
		std::cout << i << " ";
}

int main() {
	PrimeNumber();
}