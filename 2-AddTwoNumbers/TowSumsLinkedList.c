#include <stdio.h>
#include <stdlib.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
	int length1 = 0;
	int length2 = 0;
	
	struct ListNode *current1 = l1;
	struct ListNode *current2 = l2;
	while (current1 != NULL) {
		length1++;
		current1 = current1->next;
	}
	
	while (current2 != NULL) {
		length2++;
		current2 = current2->next;
	}
	
	int shouldCarry = 0;
	struct ListNode *longHead = length1 >= length2 ? l1 : l2;
	struct ListNode *shortHead = length1 < length2 ? l1 : l2;
	struct ListNode *theLast = NULL;
	while (longHead != NULL) {
		int longNum = longHead->val;
		int shortNum = 0;
		if (shortHead != NULL) {
			shortNum = shortHead->val;
			shortHead = shortHead->next;
		}
		
		int sum = longNum + shortNum + shouldCarry;
		if (sum >= 10) {
			sum -= 10;
			shouldCarry = 1;
		} else {
			shouldCarry = 0;
		}
		longHead->val = sum;
		
		if (longHead->next == NULL) {
			theLast = longHead;
		}
		
		longHead = longHead->next;
	}
	
	if (shouldCarry) {
		struct ListNode *newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->val = 1;
		newNode->next = NULL;
		theLast->next = newNode;
	}
	
	return length1 >= length2 ? l1 : l2;
}

struct ListNode* addTwoNumbersNEW(struct ListNode* l1, struct ListNode* l2) {
	struct ListNode *current1 = l1;
	struct ListNode *current2 = l2;
	struct ListNode *newHead, *newNode = NULL;
	int shouldCarry = 0;
	while (current1 != NULL || current2 != NULL || shouldCarry == 1) {
		int a = 0;
		int b = 0;
		if (current1 != NULL) {
			a = current1->val;
			current1 = current1->next;
		}
		
		if (current2 != NULL) {
			b = current2->val;
			current2 = current2->next;
		}
		
		int sums = a + b + shouldCarry;
		int val = sums % 10;
		shouldCarry = sums / 10;
		
		struct ListNode *prev = newNode;
		newNode = (struct ListNode *)malloc(sizeof(struct ListNode));
		newNode->val = val;
		newNode->next = NULL;
		if (prev != NULL) {
			prev->next = newNode;
		} else {
			newHead = newNode;
		}
	}
	
	return newHead;
}

// Print a linked list
void printLinkedList(struct ListNode *head) {
	struct ListNode *current = head;
	while (current != NULL) {
		printf("%d", current->val);
		current = current->next;
	}
	
	printf("==========\n");
}

int main(int argc, char *argv[]) {
	struct ListNode c = {9, NULL};
	struct ListNode b = {9, &c};
	struct ListNode a = {9, &b};
	struct ListNode *l1 = &a;
	printLinkedList(l1);
	
	struct ListNode e = {8, NULL};
	struct ListNode d = {2, &e};
	struct ListNode *l2 = &d;
	printLinkedList(l2);
	
	struct ListNode *newNode = addTwoNumbersNEW(l1, l2);
	printLinkedList(newNode);
	
	return 0;
}