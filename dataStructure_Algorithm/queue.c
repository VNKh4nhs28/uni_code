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

//void createQueue(queue *q){
//	bool flag = true;
//	while(flag){
//		int value;
//		int choose;
//		printf("Nhap gia tri phan tu queue: "); scanf("%d", &value);
//		putQueue(q, value);
//		printf("Tiep tuc 1 - Dung nhap 0: "); scanf("%d", &choose);
//		if (choose == 0) flag = false;
//	}
//	int value;
//	getQueue(q, &value);
//	printf("%d\n", value);
//}

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

void createQueue(queue *q){
	bool flag = true;
	while(flag){
		int value;
		int choose;
		printf("Nhap gia tri phan tu queue: "); scanf("%d", &value);
		putQueue(q, value);
		printf("Tiep tuc 1 - Dung nhap 0: "); scanf("%d", &choose);
		if (choose == 0) flag = false;
	}

}

void printfQueue(queue *q){
	while(q->count != 0){
		int value;
		getQueue(q, &value);
		printf("%d ", value);
	}
	printf("\n");
}

int main(){
	queue q;
	initQueue(&q);
	createQueue(&q);
	printfQueue(&q);
	return 0;
}
