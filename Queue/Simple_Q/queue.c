/*This program shows how simple queue works what are their operations*/
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct Queue
{
	int front, rear, size;
	unsigned int capacity;
	int *array;
};

/*This function checks if queue is full returns 0 else 1*/
int isQueueFull(struct Queue *queue)
{
	return (queue->size == queue->capacity);
}

/*This function checks if queue is empty*/
int isQueueEmpty(struct Queue *queue)
{
	return (queue->size == 0);
}

/*This function creates the queue*/
struct Queue *create_queue(unsigned int capacity)
{
	struct Queue *queue = (struct Queue *)malloc(sizeof(struct Queue));
	queue->capacity = capacity;
	queue->array = (int *)malloc(sizeof(int)*queue->capacity);
	queue->front = queue->size = 0;
	queue->rear = capacity - 1;
	return queue;
}

/*This function insert the element in the queue*/
void enqueue(struct Queue *queue, int element) 
{
	if (isQueueFull(queue))
		return;
	
	queue->rear = (queue->rear + 1)%queue->capacity;
	queue->array[queue->rear] = element;
	queue->size = queue->size + 1;
}

/*This function delete the element from the queue*/
int dequeue(struct Queue *queue)
{
	if (isQueueEmpty(queue))	
		return INT_MIN;
	
	int element;
	element = queue->array[queue->front];
	queue->front = (queue->front + 1)%queue->capacity;	
	queue->size = queue->size - 1;
	return element;
}

/*This function returns the front element from the queue*/
int getFront(struct Queue *queue)
{
	if (isQueueEmpty(queue))	
		return INT_MIN;

	return queue->array[queue->front];	
}

/*This function returns the rear element from the queue*/
int getRear(struct Queue *queue)
{
	if (isQueueEmpty(queue))	
		return INT_MIN;

	return queue->array[queue->rear];	
}

/*This is the Driver function*/
int main()
{
	struct Queue *queue = NULL;

/*Creating the queue*/
	queue = create_queue(100);

/*Enqueue operations*/
	enqueue(queue, 50);
	enqueue(queue, 60);
	enqueue(queue, 70);
	enqueue(queue, 80);

/*Dequeue operations*/
	printf("Dequeue element : [%d]\n", dequeue(queue));

/*Get front operation*/
	printf("Front : [%d]\n", getFront(queue));

/*Get rear operation*/
	printf("Rear : [%d]\n", getRear(queue));

	return 0;
}
