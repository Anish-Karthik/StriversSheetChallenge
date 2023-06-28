#include <bits/stdc++.h>

class Pair {
    public:
    int sum;
    int idx1;
    int idx2;
};

int compare(const void * a,
    const void * b) {
    return (( * (Pair * ) a).sum - ( * (Pair * ) b).sum);
}

bool commonIdx(Pair p1, Pair p2) {
    return p1.idx1 == p2.idx1 || p1.idx1 == p2.idx2 || p1.idx2 == p2.idx1 || p1.idx2 == p2.idx2;
}

string fourSum(vector < int > arr, int target, int n) {
    int size = n * (n - 1) / 2;
    Pair temp[size];
    int k = 0;
    
    for (int i = 0; i < n - 1; ++i) {
        for (int j = i + 1; j < n; ++j) {
            temp[k].sum = arr[i] + arr[j];
            temp[k].idx1 = i;
            temp[k].idx2 = j;
            ++k;
        }
    }

    qsort(temp, size, sizeof(temp[0]), compare);
    int left = 0;
    int right = size - 1;

    while (left < size && right >= 0) {
        int sum = temp[left].sum + temp[right].sum;
        if (sum == target && !commonIdx(temp[left], temp[right])) {
            return "Yes";
        } else if (sum < target) {
            ++left;
        } else {
            --right;
        }
    }

    return "No";
}
