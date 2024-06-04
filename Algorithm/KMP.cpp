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
	int m = pattern.length(); // �˻����� ����
	int n = text.length(); // �ؽ�Ʈ�� ���� 
	vector<int> pos;  // �˻��� ������ ��ġ�� pos �� ������ ��
	vector<int> pi = Fail(pattern); // ��ó�� ����. pi �迭 ���س���!

	for (int i = 0, j = 0; i < n; i++) {
		while (j > 0 && text[i] != pattern[j])// ��ġ �ϰų� �ϳ��� ��ġ�ϴ°� ���� ����(j = 0 (��, �˻��� ù ���ں��� �˻��ؾ� �ϴ� ����)�� �� ������ ����ؼ� �ִ� ������ ���λ� = ���̻� �κ��� ���λ縦 ��ġ��!
			j = pi[j - 1];
		if (text[i] == pattern[j]) { // ��ġ�Ѵٸ� 
			if (j == m - 1) { // �˻��� ������ ��� (�� ������ m - 1 ���� ��� ��ġ. �� m ���� ��ġ�ϴ� ��)
				pos.push_back(i - m + 1); // �˻� ������ ��ġ ���ڿ��� ���� �ε����� i - m + 1
				j = pi[j]; // j = pi[m - 1] �� ����
			}
			else j++; // ��ġ�ϸ� �ڿ����� �˻����� ���� ���� �˻��Ϸ� ���� �ȴ�.
		}
	}
	return pos;
}