class Solution {
  public:
    // Function to return a list containing the DFS traversal of the graph.
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        // Code here
        
        vector<bool> visited(V,false);
        vector<int> order;
        
        for(int u=0;u<V;u++)
        {  
            if(!visited[u])
                DFS(u,adj,visited,order);
        }
        return order;
    }
    
    void DFS(int u,vector<int> adj[],vector<bool> &visited,vector<int> &order){
        visited[u]=true;
        order.push_back(u);
        
        for(int v:adj[u]){
            if(!visited[v])
              DFS(v,adj,visited,order);
        }
        
    }
};
