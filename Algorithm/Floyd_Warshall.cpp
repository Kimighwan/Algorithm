#include <iostream>

int size = 4;
int INF = 10000000;
int a[4][4] = {
	{0,5,INF,8},
	{7,0,9,INF},
	{2,INF,0,4},
	{INF,INF,3,0}
};

void FloydWarshall() {
	int d[4][4];

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			d[i][j] = a[i][j];
	}

	for (int k = 0; k < size; k++) { // k는 거쳐가는 노드
		for (int i = 0; i < size; i++) // i는 출발 노드
		{
			for (int j = 0; j < size; j++) // j는 도착 노드
			{
				if (d[i][k] + d[k][j] < d[i][j])
					d[i][j] = d[i][k] + d[k][j];
			}
		}
	}

	for (int i = 0; i < size; i++) {
		for (int j = 0; j < size; j++)
			std::cout << d[i][j] << " ";
		std::cout << "\n";
	}
}

int main() {
	FloydWarshall();
}