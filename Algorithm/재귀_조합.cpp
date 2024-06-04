#include <iostream>


int arr[5];
bool select[5];

void Print() {
	for (int i = 0; i < 5; i++) {
		if(select[i] == true)  std::cout << arr[i] << " ";
	}
	std::cout << std::endl;

} 

void DFS(int index, int cnt) {
	if (cnt == 3) {
		Print();
		return;
	}

	for (int i = index; i < 5; i++) {
		if (select[i] == true) continue;
		select[i] = true;

		DFS(i, cnt + 1);
		select[i] = false;
	}
}

int main() {
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	DFS(0, 0);
}