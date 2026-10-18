int strStr(char* haystack, char* needle) {
    int h = 0;
    int n = 0;

    while (haystack[h] != '\0') {
        h++;
    }

    while (needle[n] != '\0') {
        n++;
    }

    for (int i = 0; i <= h - n; i++) {
        int j = 0;

        while (j < n && haystack[i + j] == needle[j]) {
            j++;
        }

        if (j == n) {
            return i;
        }
    }

    return -1;
}