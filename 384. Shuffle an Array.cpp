class Solution {
public:
    vector<int> myVec;
    vector<int> mySh;
    
    Solution(vector<int>& nums) {
        for (int i=0; i<nums.size();i++) {
            myVec.push_back(nums[i]);
            mySh.push_back(nums[i]);
        }
    }
    
    /** Resets the array to its original configuration and return it. */
    vector<int> reset() {
        mySh.clear();
        for (int i=0; i<myVec.size();i++) {
            mySh.push_back(myVec[i]);
        }
        return mySh;
    }
    
    /** Returns a random shuffling of the array. */
    vector<int> shuffle() {
        vector<int> res;
        int idx;
        reset();
        for (int i=0; i<myVec.size();i++) {
            idx = rand() % (myVec.size()-i);
            res.push_back(mySh[idx]);
            if (idx != myVec.size()-i-1) {
                mySh[idx] = mySh[myVec.size()-i-1];
            }
        }
        return res;
    }
        
};
