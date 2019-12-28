class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<vector<int>>& edges) {
        
        vector<int> res;
        vector<unordered_set<int>> adj(n);
        
        for (int i=0; i<edges.size();i++) {
            adj[edges[i][0]].insert(edges[i][1]);
            adj[edges[i][1]].insert(edges[i][0]);
        }
        
        
        for(int i=0; i<n; i++) {
            if (adj[i].size() ==1) {
                res.push_back(i);
            }  
        }
        
        if(n == 1) {
            res.push_back(0);
            return res;
        }
        
        while(true) {
            vector<int> next;
            for(int u : res) {
                for(int v: adj[u]) {
                    adj[v].erase(u);
                    if(adj[v].size() == 1){
                        next.push_back(v);
                    }
                }
            }
            if(next.empty())
                return res;
            res=next;
        }
 
    }
};
