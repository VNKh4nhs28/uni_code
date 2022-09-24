#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} node;

node *createNode(int value){
	node *newNode = malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void addNode(node *ptrHead, int value){
	node *ptr = ptrHead;
	node *newNode = createNode(value);
	if (ptrHead == NULL){
		ptrHead = newNode;
	}else{
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
}

void createLinkedList(node *ptrHead, int n){
	for (int i=1; i<=n; i++){
		int value;
		printf("Nhap gia tri node %d: ", i); scanf("%d", &value);
		addNode(ptrHead, value);
	}
}

void printLinkedList(node *ptrHead){
	node *ptr = ptrHead;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(){
	node *ptrHead = NULL;
	int n;
	do{
		printf("Nhap so luong phan tu linked list: "); scanf("%d", &n);
	}while(n <= 0);
	createLinkedList(ptrHead, n);
	printLinkedList(ptrHead);
	return 0;
}
