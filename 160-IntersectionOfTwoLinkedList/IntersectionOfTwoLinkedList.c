#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

struct ListNode *getIntersectionNode(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	
	if (headA == headB) {
		return headA;
	}
	
	struct ListNode *currentA = headA;
	struct ListNode *currentB = headB;
	
	int lA = 1;
	int lB = 1;
	while (currentA->next != NULL || currentB->next != NULL) {
		if (currentA->next != NULL) {
			currentA = currentA->next;
			lA += 1;
		}
		
		if (currentB->next != NULL) {
			currentB = currentB->next;
			lB += 1;
		}
	}
	
	if (currentB != currentA) {
		return NULL;
	}
	
	struct ListNode *longHead = lA >= lB ? headA : headB;
	struct ListNode *shortHead = lA < lB ? headA : headB;
	int space = lA - lB >= 0 ? (lA - lB) : (lB - lA);
	while (space > 0) {
		longHead = longHead->next;
		space -= 1;
	}
	
	while (longHead != shortHead) {
		longHead = longHead->next;
		shortHead = shortHead->next;
	}
	
	return longHead;
}

int main(int argc, char *argv[]) {
	//struct ListNode e = {5, NULL};
	//struct ListNode d = {4, &e};
	struct ListNode c = {6, NULL};
	struct ListNode b = {4, &c};
	struct ListNode a = {2, &b};
	
	struct ListNode y = {5, NULL};
	struct ListNode x = {1, &y};
	
	struct ListNode *result = getIntersectionNode(&a, &x);
	if (result == NULL) {
		printf("null");
	} else {
		printf("%d", result->val);
	}
}