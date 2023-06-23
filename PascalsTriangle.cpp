#include <bits/stdc++.h>
using namespace std;
#define lli long long int

vector<vector<lli>> printPascal(int n) 
{
  vector<vector<lli>>v = {{1}};
  if(n==1) return {{1}};
  for(int i = 1; i<n; i++){
    int j = 0;
    vector<long long>temp;
    for(int j = 0; j < i; j++){
      if(j!=0){
        temp.push_back(v[i-1][j-1] + v[i-1][j]);
      }
      else temp.push_back(1);
    }
    temp.push_back(1);
    v.push_back(temp);
  }
  return v;
}
 
