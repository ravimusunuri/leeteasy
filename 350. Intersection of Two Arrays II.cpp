class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        int n1 = nums1.size();
        int n2 = nums2.size();
        unordered_map<int, int> myHash;
        
        if ((n1==0) || (n2==0)) 
            return res;
        
        for (int i=0; i< n1; i++) {
            auto it = myHash.find(nums1[i]);
            if (it == myHash.end()) {
                myHash.insert({nums1[i],1});
            } else {
                int count = it->second;
                count++;
                myHash.erase(nums1[i]);
                myHash.insert({nums1[i],count});
            }
        }
         
        for (int j=0; j< n2; j++) {
            auto it = myHash.find(nums2[j]);
            if (it != myHash.end()) {
                int count = it->second;
                count--;
                myHash.erase(nums2[j]);
                if (count != 0) {
                    myHash.insert({nums2[j],count});
                }
                res.push_back(nums2[j]);
            }
        }
        return res;
    }
};
