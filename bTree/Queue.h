#ifndef QUEUE_H
#define QUEUE_H

#include"BTree.h"

struct Queue {
	BNode** Elem;
	int front;
	int rear;
};

Queue createQueue();
void EnQueue(Queue& queue, BNode* elem);
BNode* DeQueue(Queue & queue);
int isEmpty(Queue& queue);

#endif