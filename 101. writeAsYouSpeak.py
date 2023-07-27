def getSpokenWord(s):
    prev, res, cnt = s[0], [], 0
    for i, ch in enumerate(s):
        if prev == ch:
            cnt+= 1
        else:
            res.append(str(cnt) + prev)
            cnt = 1
        prev = ch
    res.append(str(cnt) + prev)
    return "".join(res)

def writeAsYouSpeak(n):
    # Write your code here.
    word = "1"
    for i in range(1,n):
        word = getSpokenWord(word)
    return word
