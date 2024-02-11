#include <iostream>

int main() {
	int i, j, tmp;
	int array[10] = { 1, 10, 5, 8, 7, 6, 4, 3, 2, 9 };
	for (i = 0; i < 9; i++)
	{
		j = i;
		while (array[j] > array[j + 1])
		{
			tmp = array[j];
			array[j] = array[j + 1];
			array[j + 1] = tmp;
			j--;
			if (j < 0) break;
		}
	}
}