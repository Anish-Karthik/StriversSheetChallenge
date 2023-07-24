pair<int,int> longestPalindrome(int i, int l, int r, string& s) {
    while(l >= 0 and r < s.size() and s[l] == s[r]) {
        l--; r++;
    }
    return {l+1, r-1};
}

string longestPalinSubstring(string& s) {
    int resLen = 1, l=0, r=0;
    for(int i = 0; i< s.size(); i++) {
        auto range = longestPalindrome(i, i, i, s);
        auto range2 = longestPalindrome(i, i, i+1, s);
        if (range2.second - range2.first + 1 > range.second - range.first + 1) {
            range = range2;
        }
        if(range.second - range.first + 1 > resLen) {
            tie(l, r) = range;
            resLen = r - l + 1;
        }
    }
    
    return s.substr(l, resLen);
}

