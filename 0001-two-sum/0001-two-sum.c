#include <stdlib.h>

typedef struct {
    int key;
    int value;
} HashNode;

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    HashNode map[20000];
    
    for (int i = 0; i < 20000; i++) {
        map[i].key = 2147483647; // empty marker
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        int hash = (complement % 20000 + 20000) % 20000;
        while (map[hash].key != 2147483647) {
            if (map[hash].key == complement) {
                int* ans = (int*)malloc(2 * sizeof(int));
                ans[0] = map[hash].value;
                ans[1] = i;
                *returnSize = 2;
                return ans;
            }
            hash = (hash + 1) % 20000;
        }

        hash = (nums[i] % 20000 + 20000) % 20000;
        while (map[hash].key != 2147483647) {
            hash = (hash + 1) % 20000;
        }

        map[hash].key = nums[i];
        map[hash].value = i;
    }

    *returnSize = 0;
    return NULL;
}