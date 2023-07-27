def minCharsforPalindrome(string: str) -> int:
    mismatch, left, right = 0, 0, len(string) -1
    trim = right

    while left <= right:
        if string[left] == string[right]:
            left+=1
            right-=1
        else:
            left = 0
            trim -= 1
            right= trim 
            mismatch+=1
    return mismatch
