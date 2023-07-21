#include <bits/stdc++.h>

 vector<int> nextGreaterRight(vector<int>& arr, int n)

{

    stack<pair<int, int>> s;

        vector<int> v;

        for (int i = n - 1; i >= 0; i--) {

            if (s.empty())

                v.push_back(n);

            else if (!s.empty()&&arr[i] > s.top().first)

                v.push_back(s.top().second);

            else if (!s.empty()&&arr[i] <= s.top().first) {

                while (!s.empty() && arr[i] <= s.top().first) {

                    s.pop();

                }

                if (!s.empty())

                    v.push_back(s.top().second);

                else

                    v.push_back(n);

            }

            s.push(make_pair(arr[i], i));

        }

        reverse(v.begin(), v.end());

        return v;

}

vector<int> nextSmallerLeft(vector<int>& arr, int n)

{

    stack<pair<int, int>> s;

        vector<int> v;

        for (int i = 0; i < n; i++) {

            if (s.empty())

                v.push_back(-1);

            else if (!s.empty()&&s.top().first < arr[i]) {

                v.push_back(s.top().second);

            } else if (!s.empty()&&s.top().first >= arr[i]) {

                while (!s.empty() && s.top().first >= arr[i]) {

                    s.pop();

                }

                if (!s.empty())

                    v.push_back(s.top().second);

                else

                    v.push_back(-1);

            }

            s.push(make_pair(arr[i], i));

        }

        return v;

}

 

 

 

 int largestRectangle(vector < int > & arr) {

   int n=arr.size();

   vector<int>left(n);

   vector<int>right(n);

   vector<int>width(n);

   left=nextSmallerLeft(arr,n);

   right=nextGreaterRight(arr,n);

    for (int i = 0; i < n; i++) {

            width[i] = right[i] - left[i] - 1;

        }

 

       int maxArea = 0;

        for (int i = 0; i < n; i++) {

            int area = width[i] * arr[i];

            maxArea = max(maxArea, area);

        }

 

        return maxArea;

 }
