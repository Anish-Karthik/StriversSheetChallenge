def NthRoot(n: int, m: int) -> int:
    l, r  = 0, m
    while l <= r:
        mid = (l + r) // 2;
        powMid = pow(mid, n)
        if powMid == m:
            return mid
        if powMid < m:
            l = mid+1
        else:
            r = mid-1
    return -1
