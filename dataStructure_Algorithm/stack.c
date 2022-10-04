#include <stdio.h>
#include <stdbool.h>	

#define MAX 100

typedef struct Stack{
	int top;
	int node[MAX];
}stack;

void initStack(stack *stack){
	stack->top = -1;
}

bool checkEmpty(stack *stack){
	if (stack->top == -1) return true;
	return false;
}

bool checkFull(stack *stack){
	if (stack->top == MAX-1) return true;
	return false;
}

void pushStack(stack *stack, int value){
	if (checkFull(stack)){
		printf("Stack full!\n");
		return;
	} else {
		(stack->top)++;
		stack->node[stack->top] = value;
		return;
	}
}

void popStack(stack *stack, int *value){
	if (checkEmpty(stack)){
		printf("Stack empty!\n");
		return;
	} else {
		*value = stack->node[stack->top];
		(stack->top)--;
		return;
	}
}

int main(){
	stack *stack;
	initStack(stack);
	if (checkEmpty(stack)) printf("ok\n");
	pushStack(stack, 6);
	pushStack(stack, 3);
	pushStack(stack, 10);
	int value;
	popStack(stack, &value); printf("%d ", value);
	popStack(stack, &value); printf("%d ", value);
	popStack(stack, &value); printf("%d ", value);
	return 0;
}
