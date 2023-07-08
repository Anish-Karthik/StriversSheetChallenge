def findSubsetsThatSumToK(arr, n, k) :
    res = []
    def f(ind, k, ds):
        if ind == n:
            if k == 0:
                res.append(ds)
            return
        f(ind + 1, k, ds)
        f(ind + 1, k - arr[ind], ds + [arr[ind]])
    f(0, k, [])
    return res

