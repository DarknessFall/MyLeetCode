#include <stdio.h>
#include <stdlib.h>

typedef struct {
	int maxSize;
	int size;
	int *list;
} MyStack;

MyStack *myStackCreate(int maxSize) {
	MyStack *stack = (MyStack *)malloc(sizeof(MyStack));
	stack->maxSize = maxSize;
	stack->size = 0;
	stack->list = (int *)malloc(sizeof(int) * maxSize);
	
	return stack;
}

void myStackPush(MyStack *stack, int x) {
	if (stack->size == stack->maxSize) {
		return;
	}
	
	int *a = stack->list;
	a[stack->size] = x;
	stack->size += 1;
}

int myStackPop(MyStack *stack) {
	int *a = stack->list;
	int value = a[stack->size - 1];
	a[stack->size - 1] = 0;
	stack->size -= 1;
	
	return value;
}

int myStackPeek(MyStack *stack) {
	int *a = stack->list;
	
	return a[stack->size - 1];
}

int myStackEmpty(MyStack *stack) {
	return stack->size == 0;
}

void myStackFree(MyStack *stack) {
	free(stack->list);
	free(stack);
}

typedef struct {
	MyStack *queueStack;
	MyStack *dequeueStack;
} MyQueue;

/** Initialize your data structure here. */
MyQueue* myQueueCreate(int maxSize) {
	MyQueue *queue = (MyQueue *)malloc(sizeof(MyStack));
	queue->queueStack = myStackCreate(maxSize);
	queue->dequeueStack = myStackCreate(maxSize);
	
	return queue;
}

/** Push element x to the back of queue. */
void myQueuePush(MyQueue* obj, int x) {
	if (obj->queueStack->size + obj->dequeueStack->size == obj->queueStack->maxSize) {
		return;
	}
	
	myStackPush(obj->queueStack, x);
}

/** Removes the element from in front of queue and returns that element. */
int myQueuePop(MyQueue* obj) {
	if (myStackEmpty(obj->dequeueStack)) {
		while (!myStackEmpty(obj->queueStack)) {
			myStackPush(obj->dequeueStack, myStackPop(obj->queueStack));
		}
	}
	
	return myStackPop(obj->dequeueStack);
}

/** Get the front element. */
int myQueuePeek(MyQueue* obj) {
	if (myStackEmpty(obj->dequeueStack)) {
		while (!myStackEmpty(obj->queueStack)) {
			myStackPush(obj->dequeueStack, myStackPop(obj->queueStack));
		}
	}
	
	return myStackPeek(obj->dequeueStack);
}

/** Returns whether the queue is empty. */
bool myQueueEmpty(MyQueue* obj) {
	return myStackEmpty(obj->queueStack) && myStackEmpty(obj->dequeueStack);
}

void myQueueFree(MyQueue* obj) {
	free(obj->queueStack);
	free(obj->dequeueStack);
	free(obj);
}

int main(int argc, char *argv[]) {
	MyStack *stack = myStackCreate(10);
	for (int i = 0; i < 10; i++) {
		myStackPush(stack, 10 - i);
	}
	
	printf("%d\n", myStackPop(stack));
	printf("%d", myStackPeek(stack));
	
	free(stack);
	
	return 0;
}