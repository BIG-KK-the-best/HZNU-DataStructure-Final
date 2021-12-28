#ifndef QUEUE_H
#define QUEUE_H


struct Queue
{
	int* Elem;
	int front;
	int rear;
};


Queue createQueue();
int isEmpty(Queue queue);
void EnQuque(Queue& queue, int elem);
int DeQueue(Queue& ququq);

#endif