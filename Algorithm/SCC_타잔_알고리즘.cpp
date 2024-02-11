#include <iostream>
#include <vector>
#include <stack>
constexpr int MAX = 1001;

int id, d[MAX]; // 각 노드에 고유한 번호를 할당함
bool finished[MAX];
std::vector<int> a[MAX];
std::vector<std::vector<int>> SCC;
std::stack<int> s;

int Tarjan(int x){ 
	d[x] = ++id; // 해당 노드에 대해서 알고리즘이 적용이 되어야 고유한 번호가 생김
	s.push(x);
	int parent = d[x];
	for (int i = 0; i < a[x].size(); i++) {
		int y = a[x][i];
		if (d[y] == 0) parent = std::min(Tarjan(y), parent); // DFS 활용
		else if(!finished[y]) parent = std::min(d[y], parent);
	}

	if (d[x] == parent) {
		std::vector<int> scc;
		while (1) {
			int z = s.top();
			s.pop();
			scc.push_back(z);
			finished[z] = true;
			if (z == x) break;
		}
		SCC.push_back(scc);
	}

	return parent;
}

int main() {
	int v = 11;
	a[1].push_back(2);
	a[2].push_back(3);
	a[3].push_back(1);
	a[4].push_back(2);
	a[4].push_back(5);
	a[5].push_back(7);
	a[6].push_back(5);
	a[7].push_back(6);
	a[8].push_back(5);
	a[8].push_back(9);
	a[9].push_back(10);
	a[10].push_back(11);
	a[11].push_back(3);
	a[11].push_back(8);

	for (int i = 1; i <= v; i++)
		if (d[i] == 0) Tarjan(i);
	std::cout << SCC.size() << "\n";

	for (int i = 0; i < SCC.size(); i++){
		std::cout << i + 1 << "번 째 SCC : ";
		for (int j = 0; j < SCC[i].size(); j++) {
			std::cout << SCC[i][j] << " ";
		}
		std::cout << "\n";
	}

}