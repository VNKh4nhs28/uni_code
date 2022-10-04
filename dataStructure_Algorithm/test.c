#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

//Ham thao tac ngoai linked list

//Ham thao tac trong linked list
node *createNode(int value);
void initLinkedList(node **ptrHead, node *head);
void createLinkedList(node **ptrHead);
void printLinkedList(node **ptrHead);
void addNodeTail(node **ptrHead, int value);

int main(){
	node **ptrHead;
	node *head = NULL;
	initLinkedList(ptrHead, head);
	//ptrHead = initLinkedList();
	createLinkedList(ptrHead);
	printLinkedList(ptrHead);
	return 0;
}

void initLinkedList(node **ptrHead, node *head){
	ptrHead = &head;
}

node *createNode(int value){
	node *newNode = malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void createLinkedList(node **ptrHead){
	int numOfNode;
	do{
		printf("Nhap so luong phan tu linked list muon tao: "); scanf("%d", &numOfNode);
	}while(numOfNode <= 0);
	for (int i=1; i<=numOfNode; i++){
		int value;
		printf("Nhap gia tri node thu %d: ", i); scanf("%d", &value);
		addNodeTail(ptrHead, value);
	}
}

void printLinkedList(node **ptrHead){
	node *ptr = *ptrHead;
	int i = 1;
	while(ptr != NULL){
		printf("[%d,%d]->", ptr->data, i);
		ptr = ptr->next;
		i++;
	}
	printf("NULL\n");
}

void addNodeTail(node **ptrHead, int value){
	node *newNode = createNode(value);
	if (*ptrHead == NULL){
		*ptrHead = newNode;
	} else {
		node *ptr = *ptrHead;
		while(ptr->next != NULL){
			ptr = ptr->next;
		}
		ptr->next = newNode;
	}
}
