class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int sum=accumulate(nums.begin(),nums.end(),0);
        if(sum&1) return false;
        bitset<10001> dp(1);
        for(int i:nums)
        {
            dp=dp|dp<<i;
        }
        return dp[sum/2];
    }
    
};
