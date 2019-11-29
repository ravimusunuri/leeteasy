class Solution {
public:
    int strStr(string haystack, string needle) {
        int s_len = haystack.length();
        int p_len = needle.length();
        
        if (s_len==0 && p_len==0)
            return 0;
        if (s_len < p_len)
            return -1;
        
        for (int i=0;i<=s_len-p_len;i++) {
            bool pat_match = true;
            for (int j=0; j<p_len; j++) {
                if (haystack[i+j] != needle[j]) {
                    pat_match = false;
                    break;
                }
            }
            if (pat_match) {
                return i;
            }
        }
        return -1;
    }
    
};
