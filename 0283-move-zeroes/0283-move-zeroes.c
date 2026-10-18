void moveZeroes(int* nums, int numsSize) {
    int position = 0;

    // Move all non-zero elements to the front
    for (int i = 0; i < numsSize; i++) {
        if (nums[i] != 0) {
            nums[position] = nums[i];
            position++;
        }
    }

    // Fill remaining positions with zeros
    while (position < numsSize) {
        nums[position] = 0;
        position++;
    }
}