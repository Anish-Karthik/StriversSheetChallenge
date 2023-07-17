#include <bits/stdc++.h> 
#include<vector>
void heappush(vector<int>& arr, int x) {
    arr.push_back(x);
    for (int i = arr.size() - 1; i > 0; i = (i - 1) / 2) {
        if(arr[i] < arr[(i-1)/2]) swap(arr[i], arr[(i-1)/2]);
    }
} 
int heappop(vector<int>& arr) {
    if(arr.size() == 0) return -1;
    int res = arr[0];
    swap(arr[0],arr[arr.size()-1]);
    
    arr.pop_back();
    for(int i = 0; i < arr.size()/2;) {
        int left = 2*i+1;
        int right = 2*i+2;
        if(arr[left] < arr[i]) {
            swap(arr[left], arr[i]);
            i = left;
        } else {
            swap(arr[right], arr[i]);
            i = right;
        }
    }
    return res;
}

vector<int> minHeap(int n, vector<vector<int>>& q) {
    vector<int> arr, res;
    for(auto query: q) {
        if(query[0] == 0) {
            heappush(arr, query[1]);
        } else {
            res.push_back(heappop(arr));
        }
    }
    return res;
}
