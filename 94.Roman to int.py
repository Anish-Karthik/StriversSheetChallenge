d = {x: (5 if i%2 else 1) * 10**(i//2) for i, x in enumerate("IVXLCDM")}
def romanToInt(s:str) -> int:
    res , prev = 0, 0
    for i in range(len(s)-1,-1,-1):
        if d[s[i]] < prev:
            res -= d[s[i]]
        else:
            res += d[s[i]]
        prev = d[s[i]]
    return res
