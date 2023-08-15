
class DisjointSet{

public:
	vector<int> rank,size,par;
public:
	DisjointSet(int n) {
		rank.resize(n+1,0);
		par.resize(n+1,0);
		size.resize(n+1,1);
		for(int i =0; i<n+1; i++) {
			par[i] = i;
		}
	}
public:
	void unionByRank(int u, int v) {
		int pu = findUPar(u);
		int pv = findUPar(v);
		if (pu == pv) return;
		if (rank[pu] == rank[pv]) {
			rank[pu]++;
			par[pv] = pu;
		} else if(rank[pu] > rank[pv]) {
			par[pv] = pu;
		} else {
			par[pu] = par[pv];
		}
	}
public:
	void unionBySize(int u, int v) {
		int pu = findUPar(u);
		int pv = findUPar(v);
		if (pu == pv) return;
		if(size[pu] >= size[pv]) {
			par[pv] = pu;
			size[pu] += size[pv];
		} else {
			par[pu] = pv;
			size[pv] += size[pu];
		}
	}
public:
	int findUPar(int u) {
		if(par[u] == u) return u;
		return par[u] = findUPar(par[u]);
	}
};

class Solution
{
	public:
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // prims
        vector<pair<int,pair<int,int>>> edges;
        for(int i =0; i<V; i++) {
            for(auto it: adj[i]) {
                int j = it[0];
                int wt = it[1];
                edges.push_back({wt,{i,j}});
            }
        }
        DisjointSet ds(V);
        sort(edges.begin(),edges.end());
        int mst = 0;
        for(auto it: edges) {
            int wt = it.first;
            int u = it.second.first;
            int v = it.second.second;
            if(ds.findUPar(u) == ds.findUPar(v)) continue;
            ds.unionBySize(u,v);
            mst += wt;
        }
        return mst;
        
    }
};
