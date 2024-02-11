#include <iostream>

struct Node {
	int data;
	Node* left;
	Node* right;
};

void preorder(Node* node) { // 전위 순회
	if (node) {
		std::cout << node->data << ' ';
		preorder(node->left);
		preorder(node->right);
	}
}

void inorder(Node* node) {  // 중위 순회
	if (node) {
		inorder(node->left);
		std::cout << node->data << ' ';
		inorder(node->right);
	}
}

void postorder(Node* node) { // 후위 순회
	if (node) {
		postorder(node->left);
		postorder(node->right);
		std::cout << node->data << ' ';
	}
}

int main() {
	Node nodes[16];
	for (int i = 1; i < 16; i++) {
		nodes[i].data = i;
		nodes[i].left = nullptr;
		nodes[i].right = nullptr;
	}
	for (int i = 1; i < 16; i++) {
		if (i % 2 == 0) {
			nodes[i / 2].left = &nodes[i];
		}
		else
			nodes[i / 2].right = &nodes[i];
	}
	postorder(&nodes[1]);
}