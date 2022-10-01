#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct Node{
	int data;
	struct Node *next;
}node;

//Ham thao tac ngoai
void processProgram(node **ptrHead);
void chooseMenu();
int enterValue();
int enterPos();

//Ham thao tac voi linked list
node *createNode(int value);
void createLinkedList(node **ptrHead);
void printLinkedList(node **ptrHead);
void addNodeHead(node **ptrHead, int value);
void addNodeTail(node **ptrHead, int value);
void addNodeAnyPos(node **ptrHead, int value, int pos);
void deleteNodeHead(node **ptrHead);
void deleteNodeTail(node **ptrHead);
void deleteNodeAnyPos(node **ptrHead, int pos);

int main(){
	node **ptrHead;
	node *head = NULL;
	ptrHead = &head;
	processProgram(ptrHead);
	return 0;
}

//Ham thao tac ngoai
void processProgram(node **ptrHead){
	chooseMenu();
	bool flag = false;
	do{
		int choose;
		do{
			printf("Nhap lua chon: "); scanf("%d", &choose);
		}while(choose < 0 || choose > 8);
		int value;
		int pos;
		switch(choose){
			case 1:
				createLinkedList(ptrHead);
				break;
			case 2:
				printLinkedList(ptrHead);
				break;
			case 3:
				value = enterValue();
				addNodeHead(ptrHead, value);
				break;
			case 4:
				value = enterValue();
				addNodeTail(ptrHead, value);
				break;
			case 5:
				value = enterValue();
				pos = enterPos();
				addNodeAnyPos(ptrHead, value, pos);
				break;
			case 6:
				deleteNodeHead(ptrHead);
				break;
			case 7:
				deleteNodeTail(ptrHead);
				break;
			case 8:
				pos = enterPos();
				deleteNodeAnyPos(ptrHead, pos);
				break;
			case 0:
				flag = true;
				break;
		}
	}while(!flag);
}

void chooseMenu(){
	printf("--------------------------------------------------\n");
	printf("| 1. Tao linked list                             |\n");
	printf("| 2. In linked list                              |\n");
	printf("| 3. Them mot node vao dau linked list           |\n");
	printf("| 4. Them mot node vao cuoi linked list          |\n");
	printf("| 5. Them mot node vao vi tri bat ky linked list |\n");
	printf("| 6. Xoa mot node dau linked list                |\n");
	printf("| 7. Xoa mot node cuoi linked list               |\n");
	printf("| 8. Xoa mot node vi tri bat ky linked list      |\n");	
	printf("| 9. Xoa mot node gia tri bat ky linked list     |\n");
	printf("| 0. Thoat chuong trinh                          |\n");
	printf("--------------------------------------------------\n");
}

int enterValue(){
	int value;
	printf("Nhap gia tri: "); scanf("%d", &value);
	return value;
}

int enterPos(){
	int pos;
	do{
		printf("Nhap vi tri: "); scanf("%d", &pos);
		if (pos <= 0) printf("Vi tri khong hop le (>0)\n");
	}while(pos <= 0);
	return pos;
}

//Ham thao tac voi linked list
node *createNode(int value){
	node *newNode = malloc(sizeof(node));
	newNode->data = value;
	newNode->next = NULL;
	return newNode;
}

void createLinkedList(node **ptrHead){
	int n;
	do{
		printf("Nhap so luong node muon tao: "); scanf("%d", &n);
	}while(n <= 0);

	for (int i=1; i<=n; i++){
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
		i++;
		ptr = ptr->next;
	}
	printf("NULL\n");
}

void addNodeHead(node **ptrHead, int value){
	node *newNode = createNode(value);
	if (*ptrHead == NULL){
		*ptrHead = newNode;
	} else {
		newNode->next = *ptrHead;
		*ptrHead = newNode;
	}
	printf("Them thanh cong!\n");
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
	printf("Them thanh cong!\n");
}

void addNodeAnyPos(node **ptrHead, int value, int pos){
	node *newNode = createNode(value);
	node *ptr = *ptrHead;
	int count = 1;
	bool flag = false;
	while(ptr != NULL && !flag){
		if (pos == 1){
			addNodeHead(ptrHead, value);
			flag = true;
		} else if (count+1 == pos && pos != 1){
			newNode->next = ptr->next;
			ptr->next = newNode;
			flag = true;
			printf("Them thanh cong!\n");
		} else {
			ptr = ptr->next;
			count++;
		}
	}
	if (!flag) printf("Khong tim thay vi tri can them!\n");
}

void deleteNodeHead(node **ptrHead){
	if (*ptrHead == NULL) printf("Linked list rong khong the xoa!\n");
	else {
		node *ptr = *ptrHead;
		*ptrHead = ptr->next;
		ptr->next = NULL;
		free(ptr);
		printf("Xoa thanh cong!\n");
	}
}

void deleteNodeTail(node **ptrHead){
	if (*ptrHead == NULL) printf("Linked list rong khong the xoa!\n");
	else if ((*ptrHead)->next == NULL) deleteNodeHead(ptrHead);
	else {
		node *ptrFirst = *ptrHead;
		node *ptrSecond;
		while(ptrFirst->next != NULL){
			ptrSecond = ptrFirst;
			ptrFirst = ptrFirst->next;
		}
		ptrSecond->next = NULL;
		free(ptrFirst);
		printf("Xoa thanh cong!\n");
	}
}

void deleteNodeAnyPos(node **ptrHead, int pos){
	if (*ptrHead == NULL) printf("Linked list rong khong the xoa!\n");
	else if (pos == 1) deleteNodeHead(ptrHead);
	else {
		node *ptrDelete;
		node *ptrConnect = *ptrHead;
		int countPos = 1;
		bool flag = false;
		while(ptrConnect->next != NULL && !flag){
			if (countPos+1 == pos){
				ptrDelete = ptrConnect->next;
				ptrConnect->next = ptrDelete->next;
				ptrDelete->next = NULL;
				free(ptrDelete);
				printf("Xoa thanh cong!\n");
				flag = true;
			} else {
				ptrConnect = ptrConnect->next;
				countPos++;
			}
		}
		if (!flag) printf("Vi tri xoa khong ton tai!\n");
	}
}
