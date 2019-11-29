class Solution {
public:
    bool isAnagram(string s, string t) {
        int count[26] = {0};
        
        if (s.length() != t.length()) {
            return false;
        }
        
        for (int i=0; i<s.length();i++)
            count[s[i]-'a']++;
        
        for (int i=0; i<t.length(); i++) {
            if ((count[t[i]-'a']) > 0) {
                count[t[i]-'a']--;
            } else {
                return false;
            }
        }
        
        for (int i=0; i< 26; i++) {
            if (count[i] != 0)
                return false;
        }
        return true;
    }
};
