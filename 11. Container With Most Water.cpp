class Solution {
public:
    int maxArea(vector<int>& height) {
        int i =0;
        int j = height.size()-1;
        int cur_area, max_area;
        max_area = INT_MIN;
        
        while (i < j) {
            cur_area = (j-i) * min(height[i], height[j]);
            max_area = max(cur_area, max_area);
            
            if (height[i] < height[j]) {
                i++;
            } else {
                j--;
            }
        }
        return max_area;
    }
};
