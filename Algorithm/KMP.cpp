#include <iostream>
#include <vector>
#include <string>

using namespace std;

std::vector<int> Fail(std::string pattern) {
	int m = pattern.length();

	std::vector<int> pi(m, 0);

	for (int i = 1, j = 0; i < m; i++) {
		while (j > 0 && pattern[i] != pattern[j])
			j = pi[j - 1];
		if (pattern[i] == pattern[j])
			pi[i] = ++j;
	}
	return pi;
}

vector<int> KMP(string pattern, string text) {
	int m = pattern.length(); // 검색어의 길이
	int n = text.length(); // 텍스트의 길이 
	vector<int> pos;  // 검색에 성공한 위치를 pos 에 저장할 것
	vector<int> pi = Fail(pattern); // 전처리 과정. pi 배열 구해놓기!

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])// 일치 하거나 하나도 일치하는게 없는 상태(j = 0 (즉, 검색어 첫 글자부터 검사해야 하는 상태)가 될 때까지 계속해서 최대 길이의 접두사 = 접미사 부분의 접두사를 걸치자!
			j = pi[j - 1];
		if (text[i] == pattern[j]) { // 일치한다면 
			if (j == m - 1) { // 검색에 성공한 경우 (그 이전의 m - 1 개도 모두 일치. 총 m 개가 일치하는 셈)
				pos.push_back(i - m + 1); // 검색 성공한 일치 문자열의 시작 인덱스는 i - m + 1
				j = pi[j]; // j = pi[m - 1] 와 같음
			}
			else j++; // 일치하면 자연스레 검색어의 다음 원소 검사하러 가면 된다.
		}
	}
	return pos;
}