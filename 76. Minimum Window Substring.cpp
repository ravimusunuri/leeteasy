class Solution {
public:
    string minWindow(string s, string t) {
        int s_count[256] = {0};
        int t_count[256] = {0};
        
        for (int i=0; i<t.length();i++) {
            t_count[t[i]]++;
        }
        
        int count = 0;
        int min_window = INT_MAX;
        int start = 0;
        int min_start = -1;
        
        for (int i=0; i<s.length();i++) {
            s_count[s[i]]++;
            
            if (t_count[s[i]] > 0 && s_count[s[i]] <= t_count[s[i]]) {
                count++;
            }
                
            if (count == t.length()) {   
                while ((t_count[s[start]] == 0) || (s_count[s[start]]) > (t_count[s[start]])) {
                    if ((s_count[s[start]]) > (t_count[s[start]])) {
                        s_count[s[start]]--;
                    }
                    start++;
                }
                
                if (min_window > (i-start+1)) {
                    min_start = start;
                    min_window = i-start+1;
                }
            }
        }
        
        if (min_start == -1) {
            return "";
        } else {
            return s.substr(min_start, min_window);
        }
    }
};
