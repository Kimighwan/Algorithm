#include <iostream>

int GetParent(int parent[], int x) {
	if (parent[x] == x) return x;
	return parent[x] = GetParent(parent, parent[x]);
}

void UnionNode(int parent[], int a, int b) {
	if (GetParent(parent, a) < GetParent(parent, b))
		parent[b] = a;
	else
		parent[a] = b;
}

bool FindParent(int parent[], int a, int b) {
	if (GetParent(parent, a) == GetParent(parent, b))
		return true;
	else return false;
}

int main() {
	int parent[11];
	for (int i = 0; i < 11; i++)
		parent[i] = i;
	UnionNode(parent, 1, 2);
	UnionNode(parent, 2, 3);
	UnionNode(parent, 3, 4);
	UnionNode(parent, 5, 6);
	UnionNode(parent, 6, 7);
	UnionNode(parent, 7, 8);
	std::cout << "¿¬°áµÊ??" << FindParent(parent, 1, 5) << std::endl;
	UnionNode(parent, 1, 5);
	std::cout << "¿¬°áµÊ??" << FindParent(parent, 1, 5);
}