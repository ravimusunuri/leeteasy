class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        vector<vector<string>> res;
        vector<pair<string, int>> copy;
        for(int i=0; i<strs.size(); i++) { 
            copy.push_back({strs[i], i});
        }
        
        sort(copy.begin(),copy.end());
        for(int i=0; i<copy.size(); i++) 
            sort(copy[i].first.begin(), copy[i].first.end());
        
        for(int i=0; i<copy.size(); i++) {
            vector<string> cur;
            if (copy[i].second != -1) 
                cur.push_back(strs[copy[i].second]);
            for (int j=i+1;j<copy.size();j++) {
                if ((copy[i].first == copy[j].first) && (copy[j].second != -1)) {
                    cur.push_back(strs[copy[j].second]);
                    copy[j].second = -1;
                }
            }
            if (cur.size() > 0)
                res.push_back(cur);
        }
        return res;
    }
};
