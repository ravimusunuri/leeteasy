class Solution {
public:
    int trap(vector<int>& height) {
        int total = 0;
        int sz = height.size();
        
        
        if (sz <=2 )
            return total;
        
        int leftmax[sz];
        int rightmax[sz];
        
        leftmax[0] = 0;
        for (int i=1;i<sz;i++) {
            leftmax[i] = max(leftmax[i-1], height[i-1]);
        }
        
        rightmax[sz-1] = 0;
        for (int i=sz-2;i>=0;i--) {
            rightmax[i] = max(rightmax[i+1], height[i+1]);
        }
        
        for (int i=1; i< (sz-1); i++) {
            int diff = min(leftmax[i], rightmax[i]);
            if (diff > height[i]) {
                total +=  (diff - height[i]);
            }
        }
        return total;
    }
