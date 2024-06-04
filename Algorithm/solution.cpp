#include <iostream>
#include <vector>
#include <queue>

constexpr int INF = 2147483648;
int V, E, k, dist[20001];
std::vector<std::pair<int, int>> v[20001];

int main() {
	std::ios_base::sync_with_stdio(0);
	std::cin.tie(0);

	std::cin >> V >> E;
	std::cin >> k;

	for (int i = 0; i < E; i++) {
		int a, b, w;
		std::cin >> a >> b >> w;
		v[a].emplace_back(std::make_pair(b, w));
	}

	for (int i = 1; i <= V; i++)
		dist[i] = INF;

	std::priority_queue<std::pair<int, int>> pq;
	pq.push({ 0, k });
	dist[k] = 0;

	while (!pq.empty())
	{
		int cost = -pq.top().first;
		int cur = pq.top().second;
		pq.pop();

		for (int i = 0; i < v[cur].size(); i++)
		{
			int next = v[cur][i].first;
			int nextCost = v[cur][i].second;
			if (dist[next] > cost + nextCost)
			{
				dist[next] = cost + nextCost;
				pq.push({ -dist[next], next});
			}
		}
	}

	for (int i = 1; i <= V; i++)
	{
		if (dist[i] == INF) std::cout << "INF\n";
		else std::cout << dist[i] << "\n";
	}
}