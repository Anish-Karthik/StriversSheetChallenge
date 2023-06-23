#include <bits/stdc++.h> 
using namespace std;
vector<int> nextPermutation(vector<int> &perm, int n)
{
    //  Write your code here.
    if (n == 1) return perm;
    int i, j;
    for(i = n-2; i >=0 ; i--) {
        if (perm[i] < perm[i+1]) break;
    }
    
    for(j = n-1; j >=0 ; j--) {
        if (perm[j] > perm[i]) break;
    }

    if(i >= 0) swap(perm[j], perm[i]);

    reverse(perm.begin()+i+1, perm.end());
    return perm;
}
