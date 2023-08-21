class Solution{

    vector<vector<bool>> palindrome;
    vector<int> dp;
    
    const int INF = 1e9 + 7;
    
    int f(string &str, int pos) {
        if(pos < 0)
            return 0;
        
        if(dp[pos] != -1)
            return dp[pos];
            
        int ans = INF;
        
        for(int i = pos; i >= 0; --i) {
            if(palindrome[i][pos])
                ans = min(ans, 1 + f(str, i - 1));
        }
        
        return dp[pos] = ans;
    }
    
public:
    int palindromicPartition(string str)
    {
        int n = str.length();
        
        palindrome.clear();
        palindrome.resize(n, vector<bool> (n, false));
        
        for(int i = 0; i < n; ++i)
            palindrome[i][i] = true;
            
        for(int len = 2; len <= n; ++len) {
            for(int start = 0; start + len <= n; ++start) {
                int end = start + len - 1;
                if(str[start] == str[end])
                    palindrome[start][end] = (end == start + 1 ? true :  palindrome[start + 1][end - 1]);
            }
        }
        
        dp.clear();
        dp.resize(n, -1);
        
        return f(str, n - 1) - 1;
    }
};
