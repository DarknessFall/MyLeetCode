#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

typedef struct {
	int length;
	struct ListNode *head;
	struct ListNode *tail;
} MyLinkedList;

// Print a linked list
void printLinkedList(struct ListNode *head) {
	struct ListNode *current = head;
	while (current != NULL) {
		printf("%d", current->val);
		current = current->next;
	}
	
	printf("==========\n");
}

// Make a list node
struct ListNode* makeNode(int val, struct ListNode *next) {
	struct ListNode *node = (struct ListNode *)malloc(sizeof(struct ListNode));
	node->val = val;
	node->next = next;
	
	return node;
}

/** Initialize your data structure here. */
MyLinkedList* myLinkedListCreate() {
	MyLinkedList *linkedList = (MyLinkedList *)malloc(sizeof(MyLinkedList));
	linkedList->length = 0;
	linkedList->head = NULL;
	linkedList->tail = NULL;
	
	return linkedList;
}

/** Get the value of the index-th node in the linked list. If the index is invalid, return -1. */
int myLinkedListGet(MyLinkedList* obj, int index) {	
	if (index >= obj->length || index < 0) {
		return -1;
	}
	
	struct ListNode *current = obj->head;
	for (int i = 0; i < index; i++) {
		current = current->next;
	}
	
	return current->val;
}

/** Add a node of value val before the first element of the linked list. After the insertion, the new node will be the first node of the linked list. */
void myLinkedListAddAtHead(MyLinkedList* obj, int val) {
	struct ListNode *oldHead = obj->head;
	struct ListNode *newHead = makeNode(val, oldHead);
	obj->head = newHead;
	obj->length += 1;
	if (obj->length == 1) {
		obj->tail = obj->head;
	}
}

/** Append a node of value val to the last element of the linked list. */
void myLinkedListAddAtTail(MyLinkedList* obj, int val) {
	if (obj->tail == NULL) {
		myLinkedListAddAtHead(obj, val);
		
		return;
	}
	
	struct ListNode *oldTail = obj->tail;
	struct ListNode *newTail = makeNode(val, NULL);
	oldTail->next = newTail;
	obj->tail = newTail;
	obj->length += 1;
}

/** Add a node of value val before the index-th node in the linked list. If index equals to the length of linked list, the node will be appended to the end of linked list. If index is greater than the length, the node will not be inserted. */
void myLinkedListAddAtIndex(MyLinkedList* obj, int index, int val) {
	if (index > obj->length) {
		return;
	}
	
	if (index == obj->length) {
		myLinkedListAddAtTail(obj, val);
		
		return;
	}
	
	if (index == 0) {
		myLinkedListAddAtHead(obj, val);
		
		return;
	}
	
	struct ListNode *current = obj->head;
	for (int i = 1; i < index; i++) {
		current = current->next;
	}
	
	struct ListNode *newNode = makeNode(val, current->next);
	current->next = newNode;
	obj->length += 1;
}

/** Delete the index-th node in the linked list, if the index is valid. */
void myLinkedListDeleteAtIndex(MyLinkedList* obj, int index) {
	if (index >= obj->length || index < 0) {
		return;
	}
	
	if (index == 0) {
		struct ListNode *oldHead = obj->head;
		obj->head = oldHead->next;
		obj->length -= 1;
		free(oldHead);
		
		return;
	}
	
	if (index == obj->length - 1) {
		struct ListNode *current = obj->head;
		while (current->next != obj->tail) {
			current = current->next;
		}
		
		obj->tail = current;
		obj->length -= 1;
		free(current->next);
		
		return;
	}
	
	struct ListNode *current = obj->head;
	for (int i = 1; i < index; i++) {
		current = current->next;
	}
	
	struct ListNode *rm = current->next;
	current->next = rm->next;
	obj->length -= 1;
	free(rm);
}

void myLinkedListFree(MyLinkedList* obj) {
	struct ListNode *prev = obj->head;
	struct ListNode *current = obj->head;
	while (current) {
		prev = current;
		current = current->next;
		free(prev);
	}
	
	free(obj);
}

/**
 * Your MyLinkedList struct will be instantiated and called as such:
 * struct MyLinkedList* obj = myLinkedListCreate();
 * int param_1 = myLinkedListGet(obj, index);
 * myLinkedListAddAtHead(obj, val);
 * myLinkedListAddAtTail(obj, val);
 * myLinkedListAddAtIndex(obj, index, val);
 * myLinkedListDeleteAtIndex(obj, index);
 * myLinkedListFree(obj);
 */

int main(int argc, char *argv[]) {
	MyLinkedList *obj = myLinkedListCreate();
	myLinkedListAddAtHead(obj, 5);
	printLinkedList(obj->head);
	myLinkedListAddAtHead(obj, 6);
	printLinkedList(obj->head);
	printf("%d\n", myLinkedListGet(obj, 2));
	printf("%d\n", myLinkedListGet(obj, 2));
	myLinkedListAddAtHead(obj, 7);
	printLinkedList(obj->head);
	myLinkedListAddAtIndex(obj, 1, 3);
	printLinkedList(obj->head);
	printf("%d\n", myLinkedListGet(obj, 2));
	myLinkedListAddAtIndex(obj, 2, 3);
	printLinkedList(obj->head);
	printf("%d\n", myLinkedListGet(obj, 3));
	myLinkedListAddAtHead(obj, 6);
	printLinkedList(obj->head);
	myLinkedListAddAtIndex(obj, 4, 2);
	printLinkedList(obj->head);
}