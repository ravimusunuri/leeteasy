class Solution {
public:

int longestSubstring(string s, int k) {
    return longestSubstring_recur(s, k, 0, s.size());
}

int longestSubstring_recur(const string& s, int k, int first, int last) {
    int count[26] = {0};
    for (int j = first; j < last; ++j) ++count[s[j] - 'a'];
    
    int max_len = 0;
    for (int j = first; j < last;) {
        while (j < last && count[s[j]-'a']<k) ++j;
        if (j == last) break;
        int l = j;
        while (l < last && count[s[l]-'a']>=k) ++l;
        //all chars appear more than k times
        if (j == first && l == last) return last-first; 
        max_len = max(max_len, longestSubstring_recur(s, k, j, l));
        j = l;
    }
    return max_len;
}

    
};
