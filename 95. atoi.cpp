#include <bits/stdc++.h> 

int atoi(string s) {
    int res = 0;
    for (int i = 0; i < s.length(); i++) {
        if (isdigit(s[i])) {
            res = res * 10 + s[i] - '0';
        }
    }
    if (s[0] == '-') {
        res = -res;
    }
    return res ;
}
