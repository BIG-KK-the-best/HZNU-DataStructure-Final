#include"BTree.h"
#include"Public.h"
#include"Stack.h"
#include"Queue.h"

/**
 * 树以中序序列输入，这里以递归的方式创建树
*/
BNode* createBTree()
{
	BNode* bt;
	char ch;
	scanf("%c",&ch);
	if (ch == '#') {    
		bt = NULL;
	}
	else {
		MALLOC(bt, sizeof(BNode), BNode*);
		bt->val = ch;
		bt->left = createBTree();
		bt->right = createBTree();
	}
	return bt;
}

/**
 * 层序遍历算法
*/
void Level(BNode* root)
{
	BNode* t = root;
	Queue queue = createQueue();
	EnQueue(queue, t);
	while (!isEmpty(queue)) {
		t = DeQueue(queue);
		printf("%c", t->val);
		if (t->left != NULL) {
			EnQueue(queue, t->left);
		}
		if (t->right != NULL) {
			EnQueue(queue, t->right);
		}
	}
}
/**
 * 中序非递归算法遍历二叉树
*/
void inorder(BNode* root)
{
	Stack stack = createStack();
	BNode* t = root;
	while (t != NULL || !isEmpty(stack)) {
		while (t != NULL) {
			Push(stack, t);
			t = t->left;
		}
		if (!isEmpty(stack)) {
			t = Pop(stack);
			printf("%c", t->val);
			t = t->right;
		}
	}
}

void destoryTree(BNode* root)
{
	if (root == NULL) {
		return;
	}
	BNode* l = root->left;
	BNode* r = root->right;
	FREE(root);
	destoryTree(l);
	destoryTree(r);
}
