int lengthOfLastWord(char* s) {
    int i = 0;
    int length = 0;

    while (s[i] != '\0')
        i++;

    i--;

    // Skip trailing spaces
    while (i >= 0 && s[i] == ' ')
        i--;

    // Count the last word
    while (i >= 0 && s[i] != ' ') {
        length++;
        i--;
    }

    return length;
}