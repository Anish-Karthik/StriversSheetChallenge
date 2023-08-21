class Solution:
    def wordBreak(self, s: str, wordDict: List[str]) -> bool:
        wordSet , n = set(wordDict), len(s)
        dp = {}
        def f(ind: int):
            if ind == n:
                return True
            if ind in dp:
                return dp[ind]
            for i in range(ind+1, n+1):
                if s[ind:i] in wordSet:
                    if f(i):
                        dp[ind] = True
                        return True

            dp[ind] = False
            return False
        return f(0)
