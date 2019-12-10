class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> map;
        vector<int> res;
        for(auto i:nums) map[i]++;
        
        priority_queue<pair<int,int>> pq;
        
        for(auto it=map.begin(); it!= map.end(); it++) {
            pq.push({it->second, it->first});
            if (pq.size() > (map.size()-k)) {
                pair<int, int> tmp = pq.top();
                pq.pop();
                res.push_back(tmp.second);
            }
        }
        return res;
    }
};
