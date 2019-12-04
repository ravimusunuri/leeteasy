class Solution {
public:
    vector<vector<int>> getSkyline(vector<vector<int>>& buildings) {
        vector<vector<int>> res;
        vector<pair<int,int>> seg; 
        multiset<int> mset;
        
        // segments
        for(auto b:buildings) {
            seg.push_back({b[0], -b[2]});
            seg.push_back({b[1], b[2]});
        }
        sort(seg.begin(), seg.end());

        mset.insert(0);
        int prev=0, cur=0;
        
        for(auto j:seg) {
            if (j.second<0) 
                mset.insert(-j.second);
            else
                mset.erase(mset.find(j.second));
            
            cur = *mset.rbegin();
            if (cur != prev) {
                res.push_back ({j.first,cur});
                prev = cur;
            }
        }
        return res;
    }
};
