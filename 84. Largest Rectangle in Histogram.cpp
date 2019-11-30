class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> st;
        int max_area = 0;
        int tp, area;
        int i = 0;
        
        while (i < heights.size()) {
            if (st.empty() || heights[i]>=heights[st.top()]) {
                st.push(i++);
            }  else {
                tp = st.top();
                st.pop();
                
                area = heights[tp] * (st.empty() ? i : (i-st.top()-1));
                
                if (area > max_area) {
                    max_area = area;
                }
            }
            
        }
        
        
        while (!st.empty()) {
            tp = st.top();
            st.pop();
            area = heights[tp] * (st.empty() ? i : (i-st.top()-1));
                
                if (area > max_area) {
                    max_area = area;
                }
        }
        return max_area;
    }
};
