
int countDaysTogether(char* arriveAlice, char* leaveAlice,
                      char* arriveBob, char* leaveBob) {
    int days[] = {31, 28, 31, 30, 31, 30,
                  31, 31, 30, 31, 30, 31};

    char *dates[] = {arriveAlice, leaveAlice,
                     arriveBob, leaveBob};
    int d[4];

    for (int i = 0; i < 4; i++) {
        int month = (dates[i][0] - '0') * 10
                  + (dates[i][1] - '0');
        int day = (dates[i][3] - '0') * 10
                + (dates[i][4] - '0');

        d[i] = day;
        for (int j = 0; j < month - 1; j++)
            d[i] += days[j];
    }

    int start = d[0] > d[2] ? d[0] : d[2];
    int end = d[1] < d[3] ? d[1] : d[3];

    return end >= start ? end - start + 1 : 0;
}
