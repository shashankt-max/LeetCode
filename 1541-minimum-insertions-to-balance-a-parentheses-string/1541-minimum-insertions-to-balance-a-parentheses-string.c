int minInsertions(char* s) {
    int open = 0;
    int insertions = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            if (s[i + 1] == ')') {
                i++;
            } else {
                insertions++;
            }

            if (open > 0) {
                open--;
            } else {
                insertions++;
            }
        }
    }
    insertions += open * 2;

    return insertions;
}