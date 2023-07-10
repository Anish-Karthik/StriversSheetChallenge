#include<bits/stdc++.h>
using namespace std;

string graphColoring(vector<vector<int>>& mat, int m) {
    int n = mat[0].size();
    vector<int> color(n,0);
    
    function<bool(int,int)> isSafe = [&](int node, int col)  {
        for (int k = 0; k < n; k++) {
            if (k != node && mat[k][node] == 1 && color[k] == col) {
                return false;
            }
        }
        return true;
    };

    function<bool(int)> f = [&](int node) {
        if (node == n) return true;
        for (int c = 1; c <= m; c++) {
            if(isSafe(node, c)) {
                
                color[node] = c;
                if (f(node + 1)) return true;
                color[node] = 0;
            }
        }
        return false;
    };
    
    return f(0) ? "YES" : "NO";
}
