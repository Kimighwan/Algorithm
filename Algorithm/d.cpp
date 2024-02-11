#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
const int max = 100001;

int id, p[max];
int group[max];
bool finish[max];
bool in_degree[max];
std::vector<int> v[max];
std::vector< std::vector<int>> SCC;
std::vector<int> result;
std::stack<int> s;


int Scc(int x) {
	p[x] = ++id;
	s.push(x);
	int parent = p[x];

	for (int i = 0; i < v[x].size(); i++) {
		int y = v[x][i];
		if (p[y] == 0) parent = std::min(parent, Scc(y));
		else if (!finish[y]) parent = std::min(parent, p[y]);
	}

	if (p[x] == parent) {
		std::vector<int> scc;
		while (1) {
			int z = s.top();
			s.pop();
			scc.emplace_back(z);
			finish[z] = true;
			group[z] = SCC.size();
			if (z == x) break;
		}
		SCC.emplace_back(scc);
	}
	return parent;
}

int main() {
	int t, n, m, x, y;
	std::cin >> t;
	while (t--)
	{
		SCC.clear();
		result.clear();
		std::fill(p, p + max, 0);
		std::fill(finish, finish + max, false);
		std::fill(in_degree, in_degree + max, false);
		std::cin >> n >> m;
		for (int i = 0; i < n; i++)
			v[i].clear();

		for (int i = 0; i < m; i++) {
			std::cin >> x >> y;
			v[x].emplace_back(y);
		}

		for (int i = 0; i < n; i++)
			if (p[i] == 0) Scc(i);

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < v[i].size(); j++) {
				int y = v[i][j];
				if (group[i] != group[y]) in_degree[group[y]] = true;
			}
		}

		int count = 0;
		for (int i = 0; i < SCC.size(); i++)
			if (!in_degree[i]) {
				count++;
				for (int j = 0; j < SCC[i].size(); j++)
					result.emplace_back(SCC[i][j]);
			}
		std::sort(result.begin(), result.end());
		if (count != 1)
			std::cout << "Confused" << "\n\n";
		else
		{
			for (int i = 0; i < result.size(); i++)
				std::cout << result[i] << "\n";
			std::cout << "\n";
		}
	}

	std::cout << "변경사항 추가";
}