#include <iostream>
#include <vector>
#include <queue>
#define INF 1000000000
#define N 5

int weight[N][N] = { { 0,7,4,6,1},
					 {INF, 0,INF,INF,INF},
					 {INF,2,0,5,INF},
					 {INF,3,INF,0,INF},
					 {INF,INF,INF,1,0} };

bool visit[N];
int dist[N];

int GetSmallNode() {
	int min = INF;
	int index = 0;
	for (int i = 0; i < N; i++)
	{
		if (dist[i] < min && !visit[i])
		{
			min = dist[i];
			index = i;
		}
	}
	return index;
}

void dijkstra(int start) {
	for (int i = 0; i < N; i++)
	{
		dist[i] = weight[start][i];
	}
	visit[start] = true;
	for (int i = 0; i < N - 1; i++)
	{
		int current = GetSmallNode();
		visit[current] = true;
		for (int j = 0; j < N; j++)
		{
			if (!visit[j])
				if (dist[current] + weight[current][j] < dist[j])
					dist[j] = dist[current] + weight[current][j];
		}
	}
}

std::vector<std::pair<int, int>> nodes[N];
void dijkstra_vector(int start) {
	std::priority_queue<std::pair<int, int>> pq;
	dist[start] = 0;
	pq.push({ 0, start });
	while (!pq.empty())
	{
		int cost = -pq.top().first; // �켱���� ť�� ���� ū ���� �������� �츮�� ����� �� �Ѱ��� ��� �; -�� ���� ���� �������� �����.
		int current = pq.top().second; // ���° ������� ����Ų��.
		pq.pop();
		if (dist[current] < cost) continue; // �̹� ���� ���� ��������� �ؿ� �������������ʰ� ����

		for (int i = 0; i < nodes[current].size(); i++)
		{
			int next = nodes[current][i].second;
			int nextCost = nodes[current][i].first + cost;
			if (nextCost < dist[next])
			{
				dist[next] = nextCost;
				pq.push(std::make_pair(-nextCost, next));
			}
		}
	}
	
}


int d[100];

int dp(int x) {
	if (x == 1) return 1;
	if (x == 2) return 1;
	if (d[x] != 0) return d[x];
	return d[x] = dp(x - 1) + dp(x - 2);
}



int main() {


}