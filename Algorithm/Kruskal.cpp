#include <iostream>
#include <vector>
#include <algorithm>

int GetParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent, parent[x]);
}

void UnionNode(int parent[], int a, int b) {
	if (GetParent(parent, a) < GetParent(parent, b))
		parent[b] = a;
	else
		parent[a] = b;
}

bool FindParent(int parent[], int a, int b) {
	if (GetParent(parent, a) == GetParent(parent, b))
		return true;
	else return false;
}

class Edge {
public:
	int node[2];
	int cost;
	Edge(int a, int b, int c) : node{ a, b }, cost(c) {}
	bool operator<(Edge& edge) { return this->cost < edge.cost; }
};

int main() {
	constexpr int n = 7;
	int m = 11;
	std::vector<Edge> v;
	v.emplace_back(Edge(1, 7, 12));
	v.emplace_back(Edge(1, 4, 28));
	v.emplace_back(Edge(1, 2, 67));
	v.emplace_back(Edge(1, 5, 17));
	v.emplace_back(Edge(2, 4, 24));
	v.emplace_back(Edge(2, 5, 62));
	v.emplace_back(Edge(3, 5, 20));
	v.emplace_back(Edge(3, 6, 37));
	v.emplace_back(Edge(4, 7, 13));
	v.emplace_back(Edge(5, 6, 45));
	v.emplace_back(Edge(5, 7, 73));

	std::sort(v.begin(), v.end());

	int cycle_table[n];
	for (int i = 0; i < n; i++)
		cycle_table[i] = i;

	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		if (!FindParent(cycle_table, v[i].node[0] - 1, v[i].node[1] - 1)) {
			sum += v[i].cost;
			UnionNode(cycle_table, v[i].node[0] - 1, v[i].node[1] - 1);
		}
	}
	std::cout << sum << std::endl;
}