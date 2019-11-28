class Solution {
public:
    
    bool isPalindrome(string s) {
        
        int i = 0;
        int j = s.length()-1;
        int len = s.length();
        if ((len == 0) || (len ==1)) {
            return 0;
        }
        
        char start;
        char end;
        while (i < j) {
            start = s[i];
            end = s[j];
            
            if ((!isalpha(start)) && (!isdigit(start))) {
                i++;
                continue;
            }
            
            if ((!isalpha(end)) && (!isdigit(end))) {
                j--;
                continue;
            }
            
            if (start != end) {
                return false;
            } 
            i++;
            j--;
        }
        
        return true;
        
    }
};
