#include <iostream>

int data[10] = { 4, 1, 2, 3, 9, 7, 8, 6, 10, 5 };

void QuickSort(int* data, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int tmp;

	while (i <= j) // 엇갈릴 때 까지 반복
	{
		while (i <= end && data[i] <= data[pivot]) // pivot 보다 큰 값을 찾을 때 까지 인덱스 증가
			i++;
		while (j > start && data[j] >= data[pivot]) // pivot 보다 작은 값을 찾을 때 까지 인덱스 감소
			j--;

		if (i > j) // 엇갈림 ==> 피벗과 작은 값을 교환 // 엇갈렸기에 j가 더 작은 값을 가르킴
		{
			tmp = data[pivot];
			data[pivot] = data[j];
			data[j] = tmp;
		}
		else // i와 j를 교환 ==> 큰값과 작은 값을 잘 찾은 거임
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}
	// 엇갈리고 교환 한후 집단 2개를 다시 분할 // 엇갈리면 j와 피벗이 바뀌니 j 기준 앞 뒤로 다시 시작
	QuickSort(data, start, j - 1); 
	QuickSort(data, j + 1, end);
}

int main() {
	QuickSort(data, 0, 9);

	for (int i = 0; i < 10; i++)
		std::cout << data[i] << " ";
}