class Solution {
public:
    int trap(vector<int>& height) {
        int len = height.size();
        if (len == 0)
            return 0;
        int left[len]={0};
        int right[len]={0};
        
        int max = height[0];
        left[0] = 0;
        for (int i=1; i<len;i++) {
            if (max < height[i]){
                max = height[i];
            }
            left[i] = max;
        }
        
        max = height[len-1];
        right[len-1] = 0;
        for (int i=len-2; i>=0;i--) {
            if (max < height[i]){
                max = height[i];
            }
            right[i] = max;
        }
        
        int water = 0;
        for (int i=0; i<len;i++) {
            if ((height[i]< left[i]) && (height[i]<right[i])) {
                water += (min(left[i],right[i])-height[i]);
            } 
        }
        return water;
    }
    
};
