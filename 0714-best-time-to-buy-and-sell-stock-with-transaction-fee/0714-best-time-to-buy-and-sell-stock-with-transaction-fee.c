int maxProfit(int* prices, int pricesSize, int fee) {
    int cash = 0;
    int hold = -prices[0];

    for (int i = 1; i < pricesSize; i++) {
        int prevCash = cash;
        int prevHold = hold;

        cash = (prevHold + prices[i] - fee > prevCash)
             ? prevHold + prices[i] - fee
             : prevCash;

        hold = (prevCash - prices[i] > prevHold)
             ? prevCash - prices[i]
             : prevHold;
    }

    return cash;
}