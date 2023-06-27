#include <bits/stdc++.h>

vector<int> majorityElementII(vector<int> &arr)
{

	int el1 = -1,el2 = -1, n = arr.size();
    int cnt1 = 0, cnt2 = 0;
	for(int i = 0; i < n; i++) {
		if(cnt1 == 0 && arr[i]!=el2) {
			el1 = arr[i];
            cnt1 = 1;
		} else if(cnt2 == 0 && arr[i]!=el1) {
			el2 = arr[i];
            cnt2 = 1;
		} else if(arr[i] == el1) {
            cnt1++;
        } else if(arr[i] == el2) {
            cnt2++;
        } else {
            cnt1--;cnt2--;
        }
	}
	cnt1 = 0;
    cnt2 = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == el1) cnt1++;
        else if(arr[i] == el2) cnt2++;
	}
    vector<int> res;
    if(cnt1 > n/3) res.push_back(el1);
    if(cnt2 > n/3) res.push_back(el2);
    sort(res.begin(), res.end());
	return res;
}
