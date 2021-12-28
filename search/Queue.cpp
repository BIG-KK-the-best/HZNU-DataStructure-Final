#include"Public.h"
#include"Queue.h"

Queue createQueue()
{
	Queue queue;
	MALLOC(queue.Elem, sizeof(int) * MAX_QUEUE_SIZE, int*);
	queue.front = -1;
	queue.rear = -1;
	return queue;
}

int isEmpty(Queue queue)
{
	return queue.rear == queue.front;
}

void EnQuque(Queue& queue, int elem)
{
	queue.Elem[++queue.rear % MAX_QUEUE_SIZE] = elem;
}

int DeQueue(Queue& quque)
{
	return quque.Elem[++quque.front % MAX_QUEUE_SIZE];
}
