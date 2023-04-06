#include <iostream>	
#include <vector>
using namespace std;

class Node {
public:
	int value;
	Node* parent;
	vector<Node*> childList;
	Node(Node* p, int v) {
		parent = p;
		value = v;
	}
};

class Tree {
public:
	Node* root;
	vector<Node*> nodeList;
	Tree() {
		root = new Node(nullptr, 1);
		nodeList.push_back(root);
	}
	Node* findNode(int x) {
		for (int i = 0; i < nodeList.size(); i++) {
			if (x == nodeList[i]->value) {
				return nodeList[i];
			}
		}
		return nullptr;
	}
	void insertNode(int x, int y) {
		Node* parentNode = findNode(x);
		Node* newNode = new Node(parentNode, y);
		parentNode->childList.push_back(newNode);
		nodeList.push_back(newNode);
	}
	void printDepth(int x) {
		Node* curNode = findNode(x);
		int depth = 0;
		while (curNode != root) {
			curNode = curNode->parent;
			depth++;
		}
		cout << depth << endl;
	}
};

int main() {
	int N, M;
	cin >> N >> M;
	int x, y;
	Tree tree = Tree();
	for (int i = 1; i < N; i++) {
		cin >> x >> y;
		tree.insertNode(x, y);
	}
	for (int i = 0; i < M; i++) {
		cin >> x;
		tree.printDepth(x);
	}
}