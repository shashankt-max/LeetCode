long long hoursNeeded(int* piles, int pilesSize, int k) {
    long long hours = 0;

    for (int i = 0; i < pilesSize; i++) {
        hours += ((long long)piles[i] + k - 1) / k;
    }

    return hours;
}

int minEatingSpeed(int* piles, int pilesSize, int h) {
    int left = 1;
    int right = 0;

    for (int i = 0; i < pilesSize; i++) {
        if (piles[i] > right) {
            right = piles[i];
        }
    }

    while (left < right) {
        int mid = left + (right - left) / 2;

        if (hoursNeeded(piles, pilesSize, mid) <= h) {
            right = mid;
        } else {
            left = mid + 1;
        }
    }

    return left;
}