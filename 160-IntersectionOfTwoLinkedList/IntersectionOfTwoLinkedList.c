#include <stdio.h>

typedef enum {
    true = 1,
    false = 0
} bool;

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

struct ListNode *getIntersectionNodeNEW(struct ListNode *headA, struct ListNode *headB) {
	if (headA == NULL || headB == NULL) {
		return NULL;
	}
	
	if (headA == headB) {
		return headA;
	}

	struct ListNode *tailA = headA;
	while(tailA->next != NULL){
		tailA = tailA->next;
	}
	
	tailA->next = headB;
	struct ListNode *slow = headA;
	struct ListNode *fast = headA;
	bool hasCycle = false;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast) {
			hasCycle = true;
			break;
		}
	}
	
	if (hasCycle == false) {
		tailA->next = NULL;

		return NULL;
	}
	
	slow = headA;
	while(slow != fast){
		slow = slow->next;
		fast = fast->next;
	}
	tailA->next = NULL;

	return slow;
}

int main(int argc, char *argv[]) {
	struct ListNode e = {5, NULL};
	struct ListNode d = {4, &e};
	struct ListNode c = {6, &d};
	struct ListNode b = {4, &c};
	struct ListNode a = {2, &b};
	
	struct ListNode *y = &e;
	struct ListNode x = {1, y};
	
	struct ListNode *result = getIntersectionNodeNEW(&a, &x);
	if (result == NULL) {
		printf("null");
	} else {
		printf("%d", result->val);
	}
}