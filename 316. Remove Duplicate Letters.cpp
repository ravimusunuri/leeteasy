class Solution {
    public:
        string removeDuplicateLetters(string s) {
            int sLen = s.size(), i, lastIdx[26]={0},resLen=0, included[26]={0};
            string res;
            for(i=sLen-1; i>=0 && resLen<26;--i) //generate lastIdx array
                   if(!lastIdx[s[i]-'a']) {
                    lastIdx[s[i]-'a'] = i; 
                    ++resLen;
                  }  
            for(i=0; i<sLen;++i) 
            { //scan s from left to right
                if(!included[s[i]-'a'])
                { // if s[i] is not included in s[i]
                    while(!res.empty() && s[i]<res.back() && lastIdx[res.back()-'a']>i)
                    { // pop res as much as possible to reduce res
                        included[res.back()-'a'] = 0;
                        res.pop_back();
                    }
                    included[s[i]-'a'] = 1; // add s[i] to res
                    res.push_back(s[i]);
                }
            }
            return res;
        }
};
