#include <iostream>

int data[10] = { 4, 1, 2, 3, 9, 7, 8, 6, 10, 5 };

void QuickSort(int* data, int start, int end) {
	if (start >= end) return;

	int pivot = start;
	int i = pivot + 1;
	int j = end;
	int tmp;

	while (i <= j) // ������ �� ���� �ݺ�
	{
		while (i <= end && data[i] <= data[pivot]) // pivot ���� ū ���� ã�� �� ���� �ε��� ����
			i++;
		while (j > start && data[j] >= data[pivot]) // pivot ���� ���� ���� ã�� �� ���� �ε��� ����
			j--;

		if (i > j) // ������ ==> �ǹ��� ���� ���� ��ȯ // �����ȱ⿡ j�� �� ���� ���� ����Ŵ
		{
			tmp = data[pivot];
			data[pivot] = data[j];
			data[j] = tmp;
		}
		else // i�� j�� ��ȯ ==> ū���� ���� ���� �� ã�� ����
		{
			tmp = data[i];
			data[i] = data[j];
			data[j] = tmp;
		}
	}
	// �������� ��ȯ ���� ���� 2���� �ٽ� ���� // �������� j�� �ǹ��� �ٲ�� j ���� �� �ڷ� �ٽ� ����
	QuickSort(data, start, j - 1); 
	QuickSort(data, j + 1, end);
}

int main() {
	QuickSort(data, 0, 9);

	for (int i = 0; i < 10; i++)
		std::cout << data[i] << " ";
}