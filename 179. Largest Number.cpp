class Solution {
public:
    struct StringComp{
     bool operator()(const string s1, const string s2) {
        string s1s2 = s1+s2;
        string s2s1 = s2+s1;
        return s1s2 > s2s1;
     }
    };
    
    string largestNumber(vector<int>& nums) {
        vector<string> strs;
        
        for(int i=0; i< nums.size(); i++) {
            strs.push_back(to_string(nums[i])); 
        }
        sort(strs.begin(), strs.end(), StringComp());
        string res;
        for(int i=0; i< nums.size(); i++) {
            res += strs[i];
        }
        int sum = 0;
        for(int i=0; i< nums.size(); i++) {
            if (nums[i] > 0)
                return res;
            sum += nums[i];
        }
        if (sum == 0) {
            return "0";
        }
        return res;
    }
