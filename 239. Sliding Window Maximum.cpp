class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
      
        deque<int> dq(k);
        vector<int> res;
        
        for (int i=0; i<k; i++){
            while ((dq.size() > 0) && (nums[i] >= nums[dq.back()])) {
                dq.pop_back();
            }
            dq.push_back(i);    
        } 
        int j = k;
        
        while (j < nums.size()){
            res.push_back(nums[dq.front()]);
            
            while ((dq.size() > 0) &&  (dq.front() <= (j-k))) {
                dq.pop_front();
            }
            
            while ((dq.size() > 0) && (nums[j] >= nums[dq.back()])) {
                dq.pop_back();
            }
            dq.push_back(j);
            j++;
        }
        if (dq.size() > 0) {
            res.push_back(nums[dq.front()]);
        }
        return res;
    }
};
