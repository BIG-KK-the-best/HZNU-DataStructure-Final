#include"Public.h"
#include"LStack.h"

LStack createLStack()
{
	LStack ret;
	ret.top = NULL;
	ret.size = 0;
	return ret;
}

int isEmpty(LStack stack)
{
	return stack.size == 0;
}

void Push(LStack& stack, int elem)
{
	Node* t;
	MALLOC(t, sizeof(Node), Node*);
	t->next = stack.top;
	t->val = elem;
	stack.size++;
	stack.top = t;
}

int Pop(LStack& stack)
{
	Node* t = stack.top;
	stack.top = stack.top->next;
	int ret = t->val;
	stack.size--;
	FREE(t);
	return ret;
}
