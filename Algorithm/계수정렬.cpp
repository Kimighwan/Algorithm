#include <iostream>	

int main() {
	int tmp;
	int count[100];
	int array[11] = { 1,3,1,5,8,6,32,35,78,5,4 };
	for (int i = 0; i < 100; i++)
		count[i] = 0;
	for (int i = 0; i < 11; i++)
		count[array[i] - 1]++;
	for (int i = 0; i < 100; i++) {
		if (count[i] != 0) {
			for (int j = 0; j < count[i]; j++)
				std::cout << i + 1;
		}
		std::cout << " ";
	}
}