#include <stdio.h>

int* twoSum(int* nums, int numsSize, int target) {
    int *a = malloc(2 * sizeof(int));
    for (int i = 0; i < numsSize; i++) {
        for (int j = i + 1; j < numsSize; j++) {
            if (nums[i] + nums[j] == target) {
                a[0] = i;
                a[1] = j;
                
                return a;
            }
        }
    }
    
    return NULL;
}

int main(int argc, char *argv[]) {
    int nums[] = {0, 6, 2, -1, 10};
    int *a = twoSum(nums, 5, 9);
    if (a == NULL) {
        printf("No target!\n");
    } else {
        printf("The target is [%d, %d].\n", a[0], a[1]);
    }
    
    return 0;
}