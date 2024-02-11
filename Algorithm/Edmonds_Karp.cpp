#include <iostream>
#include <queue>
#include <vector>

const int max = 100;
const int inf = 100000000;

int n = 6; // 그래프 정점 개수
int result; // 최대 유량
int capacity[max][max], flow[max][max]; // 용량과 유량 변수
int check[max]; // 방문했는지 체크
std::vector<int> v[max]; // 연결된 정점 표현

void MaxFlow(int start, int end) {
	while (1) 
	{
		std::fill(check, check + max, -1);
		std::queue<int> q;
		q.push(start);


		while (!q.empty()) 
		{
			int x = q.front();
			q.pop();
			for (int i = 0; i < v[x].size(); i++) 
			{
				int y = v[x][i];
				if (capacity[x][y] - flow[x][y] > 0 && check[y] == -1) 
				{
					q.push(y);
					check[y] = x; // 경로를 기억한다
					if (y == end) break; // 도착지에 도달하면 
				}
			}
		}

		if (check[end] == -1) break; // 모든 경로를 찾으면  while을 탈출
		int f = inf;
		for (int i = end; i != start; i = check[i]) // 거꾸로 접근하면서 최소 유량값을 가져온다
			f = std::min(f, capacity[check[i]][i] - flow[check[i]][i]);
		
		// 가져온 최소 유량을 현재 유량에 추가해준다
		for (int i = end; i != start; i = check[i]) {
			flow[check[i]][i] += f;
			flow[i][check[i]] -= f; // 음의 유량도 설정해준다.
		}
		result += f;
	}
}

int main() {
	v[1].emplace_back(2);
	v[2].emplace_back(1);
	capacity[1][2] = 12;

	v[1].emplace_back(4);
	v[4].emplace_back(1);
	capacity[1][4] = 11;

	v[2].emplace_back(3);
	v[3].emplace_back(2);
	capacity[2][3] = 6;

	v[2].emplace_back(4);
	v[4].emplace_back(2);
	capacity[2][4] = 3;

	v[2].emplace_back(5);
	v[5].emplace_back(2);
	capacity[2][5] = 5;

	v[2].emplace_back(6);
	v[6].emplace_back(2);
	capacity[2][6] = 9;

	v[3].emplace_back(6);
	v[6].emplace_back(3);
	capacity[3][6] = 8;

	v[4].emplace_back(5);
	v[5].emplace_back(4);
	capacity[4][5] = 9;

	v[5].emplace_back(3);
	v[3].emplace_back(5);
	capacity[5][3] = 3;

	v[5].emplace_back(6);
	v[6].emplace_back(5);
	capacity[5][6] = 4;

	MaxFlow(1, 6);
	std::cout << result;
}