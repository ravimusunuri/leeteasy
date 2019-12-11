class Solution {
public:
    string longestPalindrome(string s) {
        int n= s.length();
        if (n == 0)
            return "";
        if (n == 1) 
            return s;
        int max_len = 1;
        int cur_len ;
        int cur_start = -1;
        int max_start = 0;
        int x, y;
        for (int i=0;i<n; i++) {
            x = i;
            y = i + 1;
            cur_len = 0;
            cur_start = -1;
            while ((x >=0) && (y <=n) && (s[x] == s[y])) {
                cur_len +=2;
                cur_start = x;
                x--;
                y++;
            }
            
            if (max_len < cur_len) {
                max_len = cur_len;
                max_start = cur_start;
            }
            
            cur_len = 0;
            cur_start = -1;
            x = i - 1;
            y = i + 1;
            
            cur_len  =1;
            cur_start = -1;
            while ((x >=0) && (y <=n) && (s[x] == s[y])) {
                cur_len +=2;
                cur_start = x;
                x--;
                y++;
            }
            
            if (max_len < cur_len) {
                max_len = cur_len;
                max_start = cur_start;
            }
        }
        return s.substr(max_start, max_len);
    }
};
