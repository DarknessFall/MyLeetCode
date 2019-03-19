#include <stdio.h>

struct ListNode {
	int val;
	struct ListNode *next;
};

int addTwoNumbersWithSize(struct ListNode* l1, int size1, struct ListNode* l2, int size2) {

}

struct ListNode* addTwoNumbers(struct ListNode* l1, struct ListNode* l2) {
    struct ListNode *p1 = l1;
    struct ListNode *p2 = l2;
    int length1 = 0;
    int length2 = 0;
    while(p1 != NULL){
        p1 = p1->next;
        length1 += 1;
    }
    while(p2 != NULL){
        p2 = p2->next;
        length2 += 1;
    }
    
    struct ListNode *longHead = length1 >= length2 ? l1 : l2;
    struct ListNode *shortHead = length1 < length2 ? l1 : l2;

}

int main(int argc, char *argv[]) {
	return 0;
}