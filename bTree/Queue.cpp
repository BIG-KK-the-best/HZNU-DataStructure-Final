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
/**
 * 进队，这里没有考虑队满和扩容的问题，因为数据量不大
*/
void EnQueue(Queue& queue, BNode* elem)
{
	queue.Elem[(++queue.rear) % MAX_QUEUE_SIZE] = elem;
}
/**
 * 出队，这里没有考虑队空的问题
*/
BNode* DeQueue(Queue& queue)
{
	return queue.Elem[(++queue.front) % MAX_QUEUE_SIZE];
}
/**
 * 判空
*/
int isEmpty(Queue& queue)
{
	return queue.front == queue.rear;
}
