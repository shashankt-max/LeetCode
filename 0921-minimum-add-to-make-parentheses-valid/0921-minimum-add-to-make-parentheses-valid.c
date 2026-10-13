int minAddToMakeValid(char* s) {
    int open = 0;
    int additions = 0;

    for (int i = 0; s[i] != '\0'; i++) {
        if (s[i] == '(') {
            open++;
        } else {
            if (open > 0) {
                open--;
            } else {
                // Need to insert '(' before this ')'
                additions++;
            }
        }
    }

    // Remaining '(' need ')'
    additions += open;

    return additions;
}