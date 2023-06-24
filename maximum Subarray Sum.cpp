#include <bits/stdc++.h> 
long long maxSubarraySum(int arr[], int n)
{
    long long int sum = 0;
    long long int maxSum = max(arr[0],0);
    for(int i = 0; i < n; i++) {
        sum += arr[i];
        maxSum = max(maxSum, sum);
        sum =max(sum, 0ll);
    }
    return maxSum;
}
