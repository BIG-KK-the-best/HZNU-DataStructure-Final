#ifndef ASTACK_H
#define ASTACK_H


typedef struct AStack
{
	int* Elem;
	int top;
};

AStack createAStack();
int isEmpty(AStack stack);
int Push(AStack &stack, int element);
int Pop(AStack &stack);

#endif