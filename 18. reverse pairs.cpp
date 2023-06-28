#include <bits/stdc++.h> 
long long merge(vector<int> &arr, int l1, int r1, int r2) {
    int st = l1;
    int l2 = r1+1;
    int size = r2-l1+1;
    auto tmp = vector<int>(size, 0); 
    int k = 0, i = l1, j = l2;
    long long res = 0, extra = 0;
	bool flag = false;
	while (l1 <= r1) {
        while(l2 <= r2 && arr[l1] > 2 * arr[l2]) {
			l2++;
        }
		res+= l2-(r1+1);
		l1++;
    }
	l1 = i;
	l2 = j;
    while (l1 <= r1 && l2 <= r2) {
        if(arr[l1] <= arr[l2]) {
            tmp[k++] = arr[l1++]; 
        } else {
            tmp[k++] = arr[l2++];
        } 
    }
    while(l1 <= r1) tmp[k++] = arr[l1++];
    while(l2 <= r2) tmp[k++] = arr[l2++];

    i = st;
    while(i <= r2) {
        arr[i] = tmp[i - st];
        i++;
    }
    return res ;
}

long long countInv(vector<int> &arr, int low, int high) {
    if(low >= high) return 0;
    int mid = (low + high)/2;
    long long l = countInv(arr, low, mid);
    long long r = countInv(arr, mid+1, high);
    long long ops = merge(arr,low,mid,high);
    return l + r + ops;
}

int reversePairs(vector<int> &arr, int n){
	return countInv(arr,0, n-1);	
}
