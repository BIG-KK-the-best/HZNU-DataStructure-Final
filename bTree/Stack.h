#ifndef STACK_H
#define STACK_H

#include"BTree.h"
struct Stack
{
	BNode** Elem;
	int top;
};

Stack createStack();
int isEmpty(Stack stack);
void Push(Stack& stack,BNode * elem);
BNode* Pop(Stack& stack);

#endif
