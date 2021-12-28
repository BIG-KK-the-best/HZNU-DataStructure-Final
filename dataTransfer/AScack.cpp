#include"Public.h"
#include"AScack.h"

AStack createAStack()
{
	AStack ret;
	MALLOC(ret.Elem, sizeof(int) * MAX_STACK_SIZE, int*);
	ret.top = -1;
	return ret;
}

int isEmpty(AStack stack)
{
	return stack.top == -1;
}

int Push(AStack& stack, int element)
{
	stack.Elem[++stack.top] = element;
	return OK;
}

int Pop(AStack& stack)
{
	return stack.Elem[stack.top--];
}
