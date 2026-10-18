double findMaxAverage(int* nums, int numsSize, int k) {
    double sum = 0;
        for (int i = 0; i < k; i ++){
            sum += nums[i];
        }
     int maxsum = sum;
     for(int i = k; i< numsSize; i++){
        sum += nums[i];
        sum -= nums[i - k];
        if (sum > maxsum){
            maxsum = sum;
        }
     }

     return (double)maxsum/k;
}