#include "Queue.h"
#include"Public.h"
Queue createQueue()
{
	Queue queue;
	MALLOC(queue.Elem, sizeof(BNode) * MAX_QUEUE_SIZE, BNode**);
	queue.front = -1;
	queue.rear = -1;
	return queue;
}

void EnQueue(Queue& queue, BNode* elem)
{
	queue.Elem[(++queue.rear) % MAX_QUEUE_SIZE] = elem;
}

BNode* DeQueue(Queue& queue)
{
	return queue.Elem[(++queue.front) % MAX_QUEUE_SIZE];
}

int isEmpty(Queue& queue)
{
	return queue.front == queue.rear;
}
