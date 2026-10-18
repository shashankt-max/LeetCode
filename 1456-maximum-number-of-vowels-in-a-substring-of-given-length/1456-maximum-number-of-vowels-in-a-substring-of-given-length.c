int maxVowels(char* s, int k) {
    int count = 0;
    for(int i = 0; i < k; i++){
        if(s[i] == 'a' || s[i] =='e' || s[i] == 'i' ||s[i]== 'o'||s[i]=='u'){
            count++;
        }
    }
    int maxcount = count;
    for (int i = k; s[i] != '\0'; i++){
          if(s[i] == 'a' || s[i] =='e' || s[i] == 'i' ||s[i]== 'o'||s[i]=='u'){
            count++;
        }
        if (s[i-k] == 'a' || s[i-k] == 'e' ||
    s[i-k] == 'i' || s[i-k] == 'o' ||
    s[i-k] == 'u') {
    count--;
}
        if (count > maxcount){
            maxcount = count;
        }
    }
    return maxcount;
}