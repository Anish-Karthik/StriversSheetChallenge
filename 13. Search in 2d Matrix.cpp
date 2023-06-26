#include<bits/stdc++.h>
using namespace std;

bool searchMatrix(vector<vector<int>>& mat, int target) {
    int m = mat.size(), n = mat[0].size();
    auto low = 0;
    auto high = m*n - 1;

    while (low <= high) {
        auto mid = (low + high) /2;
        if (mat[mid/n][mid%n] == target) return true;
        if (target > mat[mid/n][mid%n]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }    
    return false;
}
