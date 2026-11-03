int minMoves(int* nums, int numsSize) {
    int max = nums[0];
    int moves = 0;

    for (int i = 1; i < numsSize; i++) {
        if (nums[i] > max)
            max = nums[i];
    }

    for (int i = 0; i < numsSize; i++) {
        moves += max - nums[i];
    }

    return moves;
}