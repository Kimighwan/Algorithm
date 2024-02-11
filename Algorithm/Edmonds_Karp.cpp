#include <iostream>
#include <queue>
#include <vector>

const int max = 100;
const int inf = 100000000;

int n = 6; // �׷��� ���� ����
int result; // �ִ� ����
int capacity[max][max], flow[max][max]; // �뷮�� ���� ����
int check[max]; // �湮�ߴ��� üũ
std::vector<int> v[max]; // ����� ���� ǥ��

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
					check[y] = x; // ��θ� ����Ѵ�
					if (y == end) break; // �������� �����ϸ� 
				}
			}
		}

		if (check[end] == -1) break; // ��� ��θ� ã����  while�� Ż��
		int f = inf;
		for (int i = end; i != start; i = check[i]) // �Ųٷ� �����ϸ鼭 �ּ� �������� �����´�
			f = std::min(f, capacity[check[i]][i] - flow[check[i]][i]);
		
		// ������ �ּ� ������ ���� ������ �߰����ش�
		for (int i = end; i != start; i = check[i]) {
			flow[check[i]][i] += f;
			flow[i][check[i]] -= f; // ���� ������ �������ش�.
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