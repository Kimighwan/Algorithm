#include <iostream>
#include <vector>
using namespace std;

vector<int> sieve(int n) {
	vector<int> primes;
	vector<bool> state(n + 1, true); // bool 배열을 만든다면 각각 1byte이지만
	                                 // vector<bool>는 1bit로 표현된다
	state[1] = false;
	for (int i = 2; i * i <= n; i++)
	{
		if (!state[i]) continue;
		for (int j = i * i; j <= n; j += i)
			state[j] = false;
	}

	for (int i = 2; i <= n; i++)
		if (state[i]) primes.push_back(i);
	return primes;
}