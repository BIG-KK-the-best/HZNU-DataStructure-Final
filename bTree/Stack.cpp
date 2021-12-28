#include"Public.h"
#include"Stack.h"
#include"BTree.h"

Stack createStack()
{
	Stack ret;
	MALLOC(ret.Elem,sizeof(BNode) * MAX_STACK_SIZE, BNode**);
	ret.top = -1;
	return ret;
}

int isEmpty(Stack stack)
{
	return stack.top == -1;
}

void Push(Stack& stack, BNode* elem)
{
	stack.Elem[++stack.top] = elem;
}


BNode* Pop(Stack& stack)
{
	return stack.Elem[stack.top--];
}
