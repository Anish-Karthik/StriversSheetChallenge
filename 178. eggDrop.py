class Solution:
    
    #Function to find minimum number of attempts needed in 
    #order to find the critical floor.
    def eggDrop(self,n, k):
        # code here
        dp = [0 for x in range(n+1)] 
        
        ans = 0
        
        while dp[n]<k:
            ans+=1
            for i in range(n,0,-1):
                dp[i]+= 1 + dp[i-1]

        return ans
