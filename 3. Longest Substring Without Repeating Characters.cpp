class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        if (s.length() < 2) {
            return s.length();
        }
        set<char> mySet;
        int i = 0; 
        int j = 0;
        int max_size = INT_MIN;
        while (i < s.length() and j < s.length()) {
            auto it = mySet.find(s[j]);
            if (it != mySet.end()) {
                mySet.erase(mySet.find(s[i++]));
            } else {
                mySet.insert(s[j++]);
                max_size = max(max_size, (j-i)); 
            }
        }
    
        return max_size;
    }
};
