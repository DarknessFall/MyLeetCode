#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode* removeNthFromEnd(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    int length = 0;
    struct ListNode *current = head;
    while(current != NULL){
        current = current->next;
        length += 1;
    }

    if (n > length) {
        return NULL;
    }
    
    if (n == 1 && length == 1) {
        return NULL;
    }
    
    int target = length - n;
    current = head;
    struct ListNode *targetPrevNode = NULL;
    while(target != 0){
        targetPrevNode = current;
        current = current->next;
        target -= 1;
    }

    if (targetPrevNode == NULL) {
        return head->next;
    }
    
    targetPrevNode->next = targetPrevNode->next->next;

    return head;
}

struct ListNode* removeNthFromEndNEW(struct ListNode* head, int n) {
    if (head == NULL) {
        return NULL;
    }
    
    struct ListNode *p1 = head;
    struct ListNode *p2 = head;
    for(int i = 0; i < n; i++) {
        p2 = p2->next;
    }
    
    struct ListNode *p1Prev = NULL;
    while(p2 != NULL){
        p1Prev = p1;
        p1 = p1->next;
        p2 = p2->next;
    }

    if (p1Prev == NULL) {
        return head->next;
    }

    p1Prev->next = p1Prev->next->next;

    return head;
}

int main(int argc, char *argv[]) {
    struct ListNode e = {5, NULL};
	struct ListNode d = {4, &e};
	struct ListNode c = {3, &d};
	struct ListNode b = {2, &c};
	struct ListNode a = {1, &b};

	struct ListNode *head = removeNthFromEndNEW(&a, 2);
	while(head != NULL){
        int i = head->val;
        printf("%d\n", i);
        head = head->next;
    }
    
    return 0;
}