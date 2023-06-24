#include <bits/stdc++.h> 
int maximumProfit(vector<int> &prices){
    int n = prices.size();
    int buy = prices[0];
    int profit = 0;
    for(int i = 0; i < n; i++) {
        buy = min(buy, prices[i]);
        profit = max(profit, prices[i] - buy);
    }
    return profit;
}
