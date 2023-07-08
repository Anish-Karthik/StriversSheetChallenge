from typing import List

def combinationSum2(arr: List[int], n: int, target: int) -> List[List[int]]:
    # T.C O(2^n)
    # S.C O(n)
    arr.sort()
    res = []
    def subsetSum(ind, k, ds):
        if k == 0:
            res.append(ds)
        for i in range(ind, len(arr)):
            if i != ind and arr[i] == arr[i-1]:
                continue
            subsetSum(i + 1, k - arr[i], ds +  [arr[i]])
    subsetSum(0, target, [])
    return res
