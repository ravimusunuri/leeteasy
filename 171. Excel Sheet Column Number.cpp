class Solution {
public:
    int getNum(char in) {
        return(in-'A'+1);
    }
    
    int titleToNumber(string s) {
        int num;
        int i = 1;
        num = getNum(s[0]);
        while (i < s.length()) {
            num = num* 26+getNum(s[i]);
            i++;
        }
        return num;
    }
};
