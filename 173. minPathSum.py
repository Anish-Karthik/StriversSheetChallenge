class Solution:
    def minPathSum(self, grid: List[List[int]]) -> int:
        def f(i, j):
            if(i<0 or j <0): return 1e8
            if(i == 0 and j == 0): return grid[i][j]
            if(dp[i][j]!= -1): return dp[i][j] 
            dp[i][j] = grid[i][j] + min(f(i-1,j), f(i,j-1));
            return dp[i][j]
        m, n = len(grid), len(grid[0])
        dp = [[-1]*n for i in range(m)]
        return f(m-1,n-1)
