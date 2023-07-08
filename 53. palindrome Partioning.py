def partition(s):
    # T.C = O(2^n * n) , S.C = O(n)
    res = []
    def f(ind, ds):
        if ind == len(s):
            res.append(ds[:])
        for i in range(ind, len(s)):
            tmp = s[ind:i+1] 
            if tmp == tmp[::-1]:
                f(i+1, ds+[tmp])
    f(0, [])
    return res
