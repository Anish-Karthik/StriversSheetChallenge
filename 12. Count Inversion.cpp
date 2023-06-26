#include <bits/stdc++.h> 
long long merge(long long arr[], int l1, int r1, int r2) {
    int st = l1;
    int l2 = r1+1;
    int size = r2-l1+1;
    auto tmp = vector<long long>(size, 0); 
    int k = 0;
    long long res = 0;
    while (l1 <= r1 && l2 <= r2) {
        if(arr[l1] <= arr[l2]) {
            tmp[k++] = arr[l1++]; 
        } else {
            res += (r1-l1+1);
            tmp[k++] = arr[l2++];
        } 
    }
    while(l1 <= r1) tmp[k++] = arr[l1++];
    while(l2 <= r2) tmp[k++] = arr[l2++];

    int i = st;
    while(i <= r2) {
        arr[i] = tmp[i - st];
        i++;
    }
    return res;
}

long long countInv(long long arr[], int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high)/2;
    long long l = countInv(arr, low, mid);
    long long r = countInv(arr, mid+1, high);
    long long ops = merge(arr,low,mid,high);
    return l + r + ops;
}

long long getInversions(long long arr[], int n){   
    return countInv(arr, 0, n-1);
}
