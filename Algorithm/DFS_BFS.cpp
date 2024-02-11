#include <iostream>
#include <vector>
#include <queue>

bool visited_DFS[9];
bool visited_BFS[9];

std::vector<int> graph[9] = { {}, {2,3,8}, {1,7}, {1,4,5}, {3,5}, {3,4}, {7}, {7, 6, 8}, {1, 7} };

void DFS(int x) {
	visited_DFS[x] = true;
	std::cout << x << " ";
	for (int i = 0; i < graph[x].size(); i++)
	{
		int y = graph[x][i];
		if (!visited_DFS[y])
			DFS(y);
	}
}

void BFS(int start) {
	std::queue<int> q;
	q.push(start);
	visited_BFS[start] = true;

	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		std::cout << x << ' ';
		for (int i = 0; i < graph[x].size(); i++)
		{
			int y = graph[x][i];
			if (!visited_BFS[y])
			{
				q.push(y);
				visited_BFS[y] = true;
			}
		}
	}


}

int main() {
	DFS(1);
	std::cout << std::endl;
	BFS(1);
}