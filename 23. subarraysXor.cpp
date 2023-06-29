#include <bits/stdc++.h>

int subarraysXor(vector<int> &arr, int x)
{
    unordered_map<int,int> d;
    int preXor = arr[0], res = 0;
    d[arr[0]] = 1;

    for(int i = 1; i < arr.size(); i++) {
        preXor = preXor ^ arr[i];

        res += d[preXor ^ x];
        d[preXor]++;
    }
    return res + d[x];
}
