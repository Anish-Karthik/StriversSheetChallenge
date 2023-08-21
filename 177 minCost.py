class Solution:
    def minCost(self, n: int, cuts: List[int]) -> int:
        cuts.insert(0,0)
        cuts.append(n)
        cuts.sort()
        @cache
        def f(i, j):
            if i+1 == j:
                return 0
            res = 1e9
            for k in range(i+1, j):
                ans = cuts[j] - cuts[i] + f(i, k) + f(k, j)
                res = min(ans, res)
            return res
        return f(0,len(cuts)-1)
            
