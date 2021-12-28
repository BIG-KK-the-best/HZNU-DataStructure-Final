#include"Public.h"
#include"BTree.h"
#include"Stack.h"
#include"Queue.h"
int main() {
	//创建树
	//输入示例1：+A##/*B##C##D##  --中序-->A+B*C/D  --层序-->+A/*DBC
	//输入示例2：ABD##GJ###CFH##I###    --中序-->DBJGAHFIC --层序-->ABCDGFJHI
	BNode* root = createBTree();
	printf("\n");
	Level(root);
	printf("\n");
	inorder(root);
	destoryTree(root);
}