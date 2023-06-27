#include <bits/stdc++.h>

int findMajorityElement(int arr[], int n) {
	// moores voting algo
	int el = -1, cnt = 0;
	for(int i = 0; i < n; i++) {
		if(cnt == 0) {
			el = arr[i];
		} 
		if(arr[i] == el) cnt++;
		else cnt--;
	}
	cnt = 0;
	for(int i = 0; i < n; i++) {
		if(arr[i] == el) cnt++;
	}
	return cnt>n/2? el: -1;
}
