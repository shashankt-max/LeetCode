int* asteroidCollision(int* asteroids, int asteroidsSize, int* returnSize) {
    int* stack = (int*)malloc(asteroidsSize * sizeof(int));
    int top = 0;

    for (int i = 0; i < asteroidsSize; i++) {
        int current = asteroids[i];

        // Collision happens only when stack asteroid moves right
        // and current asteroid moves left
        while (top > 0 && stack[top - 1] > 0 && current < 0) {

            if (stack[top - 1] < -current) {
                // Stack asteroid explodes
                top--;
            }
            else if (stack[top - 1] == -current) {
                // Both explode
                top--;
                current = 0;
                break;
            }
            else {
                // Current asteroid explodes
                current = 0;
                break;
            }
        }

        if (current != 0) {
            stack[top++] = current;
        }
    }

    *returnSize = top;
    return stack;
}