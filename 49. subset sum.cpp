void rec (int ind, int val, vector<int> &nums, vector<int> & res) {
	if(ind == nums.size()) {
		res.push_back(val);
		return;
	}
	rec(ind+1, val+nums[ind], nums, res);
	rec(ind+1, val, nums, res);
}
vector<int> subsetSum(vector<int> &nums){
	vector<int> res;
	rec(0, 0, nums, res);
	sort(res.begin(), res.end());
	return res;
}
