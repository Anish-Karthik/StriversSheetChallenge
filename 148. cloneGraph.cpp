/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* cloneGraph(Node* node) {
        if(!node) return node;

        unordered_map<Node*,Node*> vis;
        queue<Node*> q;

        vis[node] = new Node(node->val);
        q.push(node);

        while(!q.empty()) {
            Node* curr = q.front();q.pop();

            for(auto &neigh: curr->neighbors) {
               
                if(vis.find(neigh) == vis.end()) {
                    q.push(neigh);
                    vis[neigh] = new Node(neigh->val);
                }
                vis[curr]->neighbors.push_back(vis[neigh]);
            }
        }
        return vis[node];
    }
};
