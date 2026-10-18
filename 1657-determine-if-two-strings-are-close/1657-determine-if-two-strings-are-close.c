#include <stdbool.h>
#include <stdlib.h>
#include <string.h>

int cmpfunc(const void *a, const void *b) {
    return (*(int*)a - *(int*)b);
}

bool closeStrings(char * word1, char * word2){
    int len1 = strlen(word1);
    int len2 = strlen(word2);
    
    if (len1 != len2) return false;
    
    int count1[26] = {0};
    int count2[26] = {0};
    
    for (int i = 0; i < len1; i++) {
        count1[word1[i] - 'a']++;
        count2[word2[i] - 'a']++;
    }
    
    // Check same set of distinct characters used
    for (int i = 0; i < 26; i++) {
        if ((count1[i] == 0) != (count2[i] == 0)) {
            return false;
        }
    }
    
    // Sort frequency arrays and compare
    qsort(count1, 26, sizeof(int), cmpfunc);
    qsort(count2, 26, sizeof(int), cmpfunc);
    
    for (int i = 0; i < 26; i++) {
        if (count1[i] != count2[i]) {
            return false;
        }
    }
    
    return true;
}