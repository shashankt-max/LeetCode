#include <stdlib.h>

int** findDifference(int* nums1, int nums1Size,
                     int* nums2, int nums2Size,
                     int* returnSize,
                     int** returnColumnSizes) {

    int seen1[2001] = {0};
    int seen2[2001] = {0};

    for (int i = 0; i < nums1Size; i++)
        seen1[nums1[i] + 1000] = 1;

    for (int i = 0; i < nums2Size; i++)
        seen2[nums2[i] + 1000] = 1;

    int* arr1 = (int*)malloc(2001 * sizeof(int));
    int* arr2 = (int*)malloc(2001 * sizeof(int));

    int size1 = 0, size2 = 0;

    for (int i = 0; i < 2001; i++) {
        if (seen1[i] && !seen2[i])
            arr1[size1++] = i - 1000;

        if (seen2[i] && !seen1[i])
            arr2[size2++] = i - 1000;
    }

    int** answer = (int**)malloc(2 * sizeof(int*));

    answer[0] = (int*)malloc(size1 * sizeof(int));
    answer[1] = (int*)malloc(size2 * sizeof(int));

    for (int i = 0; i < size1; i++)
        answer[0][i] = arr1[i];

    for (int i = 0; i < size2; i++)
        answer[1][i] = arr2[i];

    free(arr1);
    free(arr2);

    *returnSize = 2;

    *returnColumnSizes = (int*)malloc(2 * sizeof(int));
    (*returnColumnSizes)[0] = size1;
    (*returnColumnSizes)[1] = size2;

    return answer;
}