class Solution{
	public:
    int maxSumIS(int arr[], int n)  
    {  
            vector<int> dp(n+1,0);
            int ans = arr[0];
            
            dp[0] = arr[0];
            
            for(int ind=1;ind<=n-1;ind++){
                dp[ind]=arr[ind];
                for(int prev=0;prev<ind;prev++){
                    if(arr[ind]>arr[prev]) dp[ind] = max(arr[ind]+dp[prev],dp[ind]);
                    ans = max(ans,dp[ind]);
                }
            }
     
            return ans;
    } 
};
