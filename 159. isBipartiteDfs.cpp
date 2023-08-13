class Solution {
public:
    bool ans=1;
    vector<int> color;
    void dfs(int i,  int c, vector<vector<int>>& graph){
        if (color[i]!=-1) return ;
        color[i]=c;
        for(int j: graph[i]){
            if( color[j]==color[i]){
                ans=0;
                return;
            }
            else{
                dfs(j, (c+1)&1, graph);
            }
        }
    }
    bool isBipartite(vector<vector<int>>& graph) {
        int n=graph.size();
        color.assign(n, -1);
        for (int i=0; i<n; i++)
            dfs(i, 1, graph);
        return ans;
    }
};
