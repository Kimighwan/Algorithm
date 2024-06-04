#include <iostream>
#include <vector>

using namespace std;

int arr[5];
bool select[5];
vector<int> v;

void Print() {
	for (int i = 0; i < v.size(); i++) cout << v[i] << " ";
	cout << endl;
}

void DFS(int cnt) {
	if (cnt == 3) {
		Print();
		return;
	}

	for (int i = 0; i < 5; i++) {
		if (select[i] == true) continue;
		select[i] = true;
		v.emplace_back(arr[i]);
		DFS(cnt + 1);
		v.pop_back();
		select[i] = false;
	}
}

int main() {
	arr[0] = 1;
	arr[1] = 2;
	arr[2] = 3;
	arr[3] = 4;
	arr[4] = 5;

	DFS(0);
}