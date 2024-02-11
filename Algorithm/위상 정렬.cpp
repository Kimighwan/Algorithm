#include <iostream>
#include <vector>
#include <queue>
#include <stack>

int n;
int in_degree[10];
std::vector<int> a[10];

void TopologySort_BFS() {
	int result[10];
	std::queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (in_degree[i] == 0)  q.push(i);
	}

	for (int i = 1; i <= n; i++) {
		if (q.empty()) {
			std::cout << "사이클이 있는 그래프 - 위상 정렬 불가능\n";
			return;
		}
		int x = q.front();
		q.pop();
		result[i] = x;
		for (int i = 0; i < a[x].size(); i++) {
			int y = a[x][i];
			if (--in_degree[y] == 0) {
				q.push(y);
			}
		}
	}

	for (int i = 1; i <= n; i++)
		std::cout << result[i] << " ";
}

bool visited[10];
std::vector<int> graph[10];
std::stack<int> s;

void DFS(int x) {
	if (visited[x]) return;
	visited[x] = true;

	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited[y])
			DFS(y);
	}
	s.push(x);
}

void TopologySort_DFS() {

	for (int i = 0; i < 6; i++) {
		if (!visited[i])
			DFS(i);
	}
}

int main() {
	n = 7;
	a[1].push_back(2);
	in_degree[2]++;
	a[1].push_back(5);
	in_degree[5]++;
	a[2].push_back(3);
	in_degree[3]++;
	a[3].push_back(4);
	in_degree[4]++;
	a[4].push_back(6);
	in_degree[6]++;
	a[5].push_back(6);
	in_degree[6]++;
	a[6].push_back(7);
	in_degree[7]++;
	// TopologySort_BFS();

	graph[0].emplace_back(1);
	graph[1].emplace_back(2);
	graph[2].emplace_back(5);
	graph[3].emplace_back(0);
	graph[3].emplace_back(4);
	graph[4].emplace_back(1);
	graph[4].emplace_back(2);

	TopologySort_DFS();

	for (int i = 0; i < s.size(); i++) {
		std::cout << s.top() << " ";
		s.pop();
	}
}