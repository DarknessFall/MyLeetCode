#include <stdio.h>

struct ListNode {
    int val;
    struct ListNode *next;
};

struct ListNode *reverseLinkedList(struct ListNode *head) {
    if (head == NULL || head->next == NULL) {
        return head;
    }

    struct ListNode *prev = NULL;
    struct ListNode *current = head;
    struct ListNode *next = head->next;
    while(current != NULL){
        next = current->next;
        current->next = prev;
        prev = current;
        current = next;
    }
    
    return prev;
}

struct ListNode* reverseBetween(struct ListNode* head, int m, int n) {
    if (head == NULL || head->next == NULL) {
        return head;
    }
    
    struct ListNode *startNode = head;
    struct ListNode *endNode = head;
    struct ListNode *startPrev = head;
    for (int i = 1; i < n; i++) {
        if (i < m) {
            startPrev = startNode;
            startNode = startNode->next;
        }

        endNode = endNode->next;
    }
    struct ListNode *theNextNode = endNode->next;
    endNode->next = NULL;
    struct ListNode *newHead = reverseLinkedList(startNode);
    startPrev->next = endNode;
    startNode->next = theNextNode;

    if (startNode == head) {
        return endNode;
    }

    return head;
}

int main(int argc, char *argv[]) {
    return 0;
}