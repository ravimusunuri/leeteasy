class Solution {
public:
    int firstUniqChar(string s) {
    int len = s.length();
    int freq[26] = {0};
       for(int i=0; i<len;i++) freq[s[i]-'a']++;
        
       for(int i=0;i<len;i++) 
           if(freq[s[i]-'a']==1) return i;
   
        return -1;
        }
};
