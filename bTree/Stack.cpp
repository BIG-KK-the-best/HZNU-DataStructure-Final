#include"Public.h"
#include"Stack.h"
#include"BTree.h"


/**
 * 栈这部分同样没有考虑栈空或满的情况，就这考试而言，完全够用
*/

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
