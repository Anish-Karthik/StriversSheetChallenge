#include <bits/stdc++.h> 
int uniquePaths(int m, int n) {
	int N = m + n - 2;
	double ans = 1;
	// NCn-1 or NCm-1
	int r = min(n,m) -1;
	// nCr = n!/(r! * (n-r)!) = n!/r!/(n-r)!
	for(int i = 1; i <= r; i++) {
		ans = (ans * (N - r + i)) / i;
	}
	return ans;
}
