#include <stdio.h>

#define MAX 100

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

int main(){
	queue *q;
	initQueue(q);
	return 0;
}
