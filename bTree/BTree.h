#ifndef BTREE_H
#define BTREE_H

struct BNode {
	char val;
	BNode* left;
	BNode* right;
};

BNode* createBTree();

void Level(BNode* root);
void inorder(BNode* root);
void destoryTree(BNode* root);

#endif