class Solution
{
	public:
    vector <int> dijkstra(int V, vector<vector<int>> adj[], int S)
    {
        // Code here
        queue<pair<int,int>> q;
        vector<int> dist(V,1e9);
        dist[S] = 0;
        q.push({dist[S],S});
        while (!q.empty()) {
            int dis,node;
            tie(dis,node) = q.front();
            q.pop();
            
            for(auto it: adj[node]) {
                int adjNode = it[0];
                int egdeWt = it[1];
                if (dist[adjNode] > dis + egdeWt) {
                    dist[adjNode] = dis + egdeWt;
                    q.push({dist[adjNode],adjNode});
                }
            }
        }
        return dist;
    }
};
