#include <stdio.h>
#include <stdbool.h>

#define MAX 50

typedef struct Queue{
	int head;
	int tail;
	int count;
	int node[MAX];
}queue;

void initQueue(queue *q){
	q->head = 0;
	q->tail = MAX-1;
	q->count = 0;
}

bool emptyQueue(queue *q){
	if (q->count == 0) return true;
	return false;
}

void putQueue(queue *q, int value){
	if (q->count == MAX){
		printf("Queue full\n");
	} else {
		if (q->tail == MAX-1){
			q->tail = 0;
		} else {
			(q->tail)++;
		}
	}
	q->node[q->tail] = value;
	(q->count)++;
}

void getQueue(queue *q, int *value){
	if (emptyQueue(q)){
		printf("Queue empty\n");
	} else {
		*value = q->node[q->head];
		if (q->head == MAX-1){
			q->head = 0;
		} else {
			(q->head)++;
		}
		(q->count)--;
	}
}

int main(){
	queue q;
	initQueue(&q);
	putQueue(&q, 5);
	putQueue(&q, 6);
	putQueue(&q, 7);
	int value;
	getQueue(&q, &value); printf("%d ", value);
	getQueue(&q, &value); printf("%d ", value);
	getQueue(&q, &value); printf("%d ", value);
	return 0;
}
