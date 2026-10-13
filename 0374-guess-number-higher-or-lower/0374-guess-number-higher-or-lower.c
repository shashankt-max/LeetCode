int guess(int num);

int guessNumber(int n) {
    long long left = 1;
    long long right = n;

    while (left <= right) {
        long long mid = left + (right - left) / 2;

        int result = guess((int)mid);

        if (result == 0)
            return (int)mid;
        else if (result == -1)
            right = mid - 1;
        else
            left = mid + 1;
    }

    return -1;
}