#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
} node;

node *ptrHead = NULL;

node *createNode(int value){
	node *newNode = malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void addNode(int value){
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

void createLinkedList(int n){
	for (int i=1; i<=n; i++){
		int value;
		printf("Nhap gia tri node %d: ", i); scanf("%d", &value);
		addNode(value);
	}
}

void printLinkedList(){
	node *ptr = ptrHead;
	while(ptr != NULL){
		printf("%d ", ptr->data);
		ptr = ptr->next;
	}
	printf("\n");
}

int main(){
	int n;
	do{
		printf("Nhap so luong phan tu linked list: "); scanf("%d", &n);
	}while(n <= 0);
	createLinkedList(n);
	printLinkedList();
	return 0;
}
