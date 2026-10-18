int compress(char* chars, int charsSize) {
    int write = 0;  // position to write compressed data
    int read = 0;   // position to read original data

    while (read < charsSize) {
        char current = chars[read];
        int count = 0;

        // Count consecutive occurrences
        while (read < charsSize && chars[read] == current) {
            read++;
            count++;
        }

        // Write the character
        chars[write++] = current;

        // Write the count if > 1
        if (count > 1) {
            char buffer[10];
            int len = 0;

            while (count > 0) {
                buffer[len++] = (count % 10) + '0';
                count /= 10;
            }

            // Reverse digits into chars
            for (int i = len - 1; i >= 0; i--) {
                chars[write++] = buffer[i];
            }
        }
    }

    return write;
}