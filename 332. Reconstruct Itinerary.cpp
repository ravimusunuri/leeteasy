class Solution {
public:
    unordered_map<string, priority_queue<string, vector<string>, greater<string>>> graph;
    vector<string> res; 
    void dfs(string str){
        auto& e = graph[str];
        while(!e.empty()) {
            string n = e.top();
            e.pop();
            dfs(n);
        }
        res.push_back(str);
    }
    
    vector<string> findItinerary(vector<vector<string>>& tickets) {
        for(auto e : tickets) {
            graph[e[0]].push(e[1]);
        }
        dfs("JFK");
        reverse(res.begin(), res.end());
        return res;
    }
};
