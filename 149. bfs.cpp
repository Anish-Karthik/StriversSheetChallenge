class Solution {
  public:
    // Function to return Breadth First Traversal of given graph.
    vector<int> bfsOfGraph(int V, vector<int> adj[],int node = 0) {
        // Code here
        vector<int> vis(V,0);
        vector<int> bfs;
        queue<int> q;
        q.push(node);
        vis[node] = 1;
        while(!q.empty()) {
            node = q.front();
            bfs.push_back(node);
            
            q.pop();
            for(auto neigh: adj[node]) {
                if(!vis[neigh]) {
                    q.push(neigh);
                    vis[neigh] = 1;
                }
            }
        }
        return bfs;
    }
};
