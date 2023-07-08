#include <bits/stdc++.h> 

void rec(int ind, vector<int>& tmp, vector<int> &nums, vector<vector<int>> &res) {
	res.push_back(tmp);
    for(int i = ind; i < nums.size(); i++) {
        if(i != ind && nums[i] == nums[i-1]) continue;
        tmp.push_back(nums[i]);
        rec(i+1, tmp, nums, res);
        tmp.pop_back();
    }
}

vector<vector<int>> uniqueSubsets(int n, vector<int> &arr)
{
    vector<vector<int>> res;
    vector<int> tmp;
    sort(arr.begin(), arr.end());
    rec(0, tmp, arr, res);
    return res;
}
