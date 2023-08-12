#include<bits/stdc++.h>

void bfs(int v,vector<int> &visited,vector<vector<int>> &ad,vector<int> &indegree,vector<int> &ans){

  queue<int>q;

  for(int i=1;i<indegree.size();i++){

    if (indegree[i] == 0) {

      q.push(i);

      visited[i] = 1;

    }

  }

  while(!q.empty()){

    int c=q.front();

    q.pop();

    ans.push_back(c);

    for(auto n:ad[c]){

      indegree[n]--;

      if(indegree[n]==0 && visited[n]==0){

        q.push(n);

        visited[n]=1;

      }

    }

  }

}

int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {

  vector<vector<int>>ad(n+1);

  vector<int>indegree(n+1,0);

  for(int i=0;i<edges.size();i++){

    int u=edges[i].first,v=edges[i].second;

    ad[u].push_back(v);

    indegree[v]++;

  }

  vector<int>visited(n+1,0);

  vector<int>ans;

  for(int i=1;i<=n;i++){

    if(visited[i]==0){

      bfs(i,visited,ad,indegree,ans);

    }

  }

  if(ans.size()==n)return 0;

  return 1;

}
