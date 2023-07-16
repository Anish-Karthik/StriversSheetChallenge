#include <bits/stdc++.h> 
vector<int> mergeKSortedArrays(vector<vector<int>>&karr, int k)
{
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq; 
    vector<int>ans;
    for(int i=0;i<k;i++) pq.push({karr[i][0], 0, i});
    while(!pq.empty()){
        auto x=pq.top();
        int e=x[0],i=x[1],a=x[2];
        pq.pop();
        ans.push_back(e);
        if(i+1<karr[a].size())
            pq.push({karr[a][i+1], i+1, a});
    }
    return ans;
}
