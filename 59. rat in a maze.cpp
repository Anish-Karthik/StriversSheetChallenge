#include <bits/stdc++.h> 
vector<vector<int> > ratInAMaze(vector<vector<int> > &maze, int n){
  
  vector<vector<int>> res;
  if(maze[0][0] == 0 || maze[n-1][n-1] == 0) return res;

  int di[] = {1,-1,0,0};
  int dj[] = {0, 0, 1, -1};
  auto vis = vector<vector<int>>(n, vector<int>(n,0));
  function<void(int,int)> f = [&] (int i, int j) {
    vis[i][j] = 1;
    if (i == n-1 && j == n-1) {
      vector<int> tmp;
      for(int i = 0; i < n; i++) {
        for(int j = 0; j<n; j++) {
          tmp.push_back(vis[i][j]);
        }
      }
      vis[i][j] = 0;
      res.push_back(tmp);
      return;
    }

    for(int x=0; x<4; x++) {
      int ni = i + di[x];
      int nj = j + dj[x];
      if(0<= ni && ni < n && 0 <= nj && nj < n && maze[ni][nj] && !vis[ni][nj]) {
        f(ni, nj);
      }
    }
    vis[i][j] = 0;
  };

  f(0,0);
  return res;
}
