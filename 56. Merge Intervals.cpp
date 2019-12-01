class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        sort(intervals.begin(), intervals.end());
        
        vector<vector<int>> res;
        int i = 0;
        int sz = intervals.size();
        stack<vector<int>> st;
        
        while (i< sz) {
            vector<int> cur = intervals[i];
            if (!st.empty()) {
                vector<int> top= st.top();
                
                if (cur[0] <= top[1]) {
                    st.pop();
                    top[1] = max (top[1], cur[1]);
                    st.push(top);
                } else {
                    st.push(cur);
                }
            } else {
                st.push(cur);
            }
            i++;
        }
        
        while (!st.empty()) {
            vector<int> top = st.top();
            st.pop();
            res.push_back(top);
        }
        
        return res;
    }
};
