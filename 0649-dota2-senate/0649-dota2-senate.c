#include <stdlib.h>
#include <string.h>

char* predictPartyVictory(char* senate) {
    int n = strlen(senate);

    int *radiant = (int*)malloc(n * 2 * sizeof(int));
    int *dire = (int*)malloc(n * 2 * sizeof(int));

    int rf = 0, rr = 0;
    int df = 0, dr = 0;

    // Store positions of both parties
    for (int i = 0; i < n; i++) {
        if (senate[i] == 'R')
            radiant[rr++] = i;
        else
            dire[dr++] = i;
    }

    while (rf < rr && df < dr) {
        int r = radiant[rf++];
        int d = dire[df++];

        // Senator who comes first bans the other
        if (r < d) {
            radiant[rr++] = r + n;
        } else {
            dire[dr++] = d + n;
        }
    }

    char *answer;

    if (rf < rr)
        answer = "Radiant";
    else
        answer = "Dire";

    free(radiant);
    free(dire);

    return answer;
}