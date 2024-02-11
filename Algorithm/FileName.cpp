#include <iostream>
#include <vector>
#include <queue>
constexpr int max = 10001;

class Edge {
public:
	int node;
	int time;
	Edge(int n, int t) {
		node = n;
		time = t;
	}
};

int n, start, finish; // ���� ����, ���� ����, ���� ����
int in_degree[max], result[max];
bool is_check[max]; // �Ӱ� ��ο� ��� ������ 1���� ������ �Ǵ� ó���Ǿ����� üũ
std::vector<Edge> a[max]; // ���� -> ���� ���
std::vector<Edge> b[max]; // ���� -> ���� ���

void TopologySort() {
	std::queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < a[x].size(); i++) {
			Edge y = a[x][i];
			if (result[y.node] <= result[x] + y.time)
				result[y.node] = result[x] + y.time;
			if (--in_degree[y.node] == 0)
				q.push(y.node);
		}
	}

	int count = 0;
	q.push(finish);
	while (!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = 0; i < b[x].size(); i++) {
			Edge y = b[x][i];
			if (result[x] - result[y.node] == y.time) {
				count++;
				if (!is_check[y.node]) {
					q.push(y.node);
					is_check[y.node] = true;
				}
			}
		}

	}
	std::cout << result[finish] << "\n" << count;
}

int main() {
	int m, s, f, t;
	std::cin >> n;
	std::cin >> m;
	for(int i = 0; i < m; i++){
		std::cin >> s >> f >> t;
		a[s].emplace_back(Edge(f, t));
		b[f].emplace_back(Edge(s, t));
		in_degree[f]++;
	}
	std::cin >> start >> finish;
	TopologySort();
}