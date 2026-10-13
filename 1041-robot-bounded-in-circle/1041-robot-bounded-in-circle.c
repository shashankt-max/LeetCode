#include <stdbool.h>

bool isRobotBounded(char* instructions) {
    int x = 0;
    int y = 0;

    // 0 = North
    // 1 = East
    // 2 = South
    // 3 = West
    int direction = 0;

    for (int i = 0; instructions[i] != '\0'; i++) {

        if (instructions[i] == 'G') {
            if (direction == 0)
                y++;
            else if (direction == 1)
                x++;
            else if (direction == 2)
                y--;
            else
                x--;
        }
        else if (instructions[i] == 'L') {
            direction = (direction + 3) % 4;
        }
        else if (instructions[i] == 'R') {
            direction = (direction + 1) % 4;
        }
    }

    return (x == 0 && y == 0) || direction != 0;
}