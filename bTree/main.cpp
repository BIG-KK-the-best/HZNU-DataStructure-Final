#include"Public.h"
#include"BTree.h"
#include"Stack.h"
#include"Queue.h"
int main() {
	BNode* root = createBTree();
	printf("\n");
	Level(root);
	printf("\n");
	inorder(root);
	destoryTree(root);
}