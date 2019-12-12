class Solution {
public:
    bool isPalindrome(string s) {
        int i = 0;
        int j = s.length()-1;
        
        if (s.length() == 0)
            return true;
        int count =0;
        while (i<j) {
            while (!isalnum(s[i]) && (i<j)) {
                i++;
                count++;
            }
            while (!isalnum(s[j]) && (i<j)) {
                j--;
                count++;
            }
            
            if (tolower(s[i]) != tolower(s[j])) {
                return false;
            }
            i++;
            j--;
        }
        if (count == s.length()) {
            return false;
        }
        return true;
    }
};
