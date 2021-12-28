#ifndef LSTACK_H
#define LSTACK_H

typedef struct Node {
	int val;
	Node* next;
};

typedef struct LStack 
{
	Node* top;
	int size;
};

LStack createLStack();
int isEmpty(LStack stack);
void Push(LStack& stack, int val);
int Pop(LStack& stack);

#endif