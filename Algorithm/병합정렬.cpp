#include <iostream>

int sorted[8];

void Merge(int data[], int start, int middle, int end) {
	int i = start;
	int j = middle + 1;
	int k = start;
	while (i <= middle && j <= end) // 작은 값 먼저 배열에 삽입
	{
		if (data[i] <= data[j])
		{
			sorted[k] = data[i++];

		}
		else
		{
			sorted[k] = data[j++];
		}
		k++;
	}
	// 남은 데이터 삽입
	if (i > middle)
	{
		for (int n = j; n <= end; n++)
			sorted[k++] = data[n];
		
	}
	else
	{
		for (int n = i; n <= middle; n++)
			sorted[k++] = data[n];
	}

	for (int n = start; n <= end; n++)
		data[n] = sorted[n];
}

void MergeSort(int data[], int start, int end) {
	if (start < end) {
		int middle = (start + end) / 2;
		MergeSort(data, start, middle);
		MergeSort(data, middle + 1, end);
		Merge(data, start, middle, end);
	}
}

int main() {
	int array[8] = { 7,6,5,8,3,5,9,1 };
	MergeSort(array, 0, 7);
	for (int i = 0; i < 8; i++)
		std::cout << array[i] << " ";
}