class Solution {
public:
    
    void helper(string digits, int idx, string& cur, vector<string>&res, vector<string> tb) {
        if (idx == digits.size()) {
            res.push_back(cur);
            return;
        }
        
        string s = tb[digits[idx]-'0'];
        for (int i=0; i< s.length();i++) {
            cur[idx]=s[i];
            helper(digits, idx+1, cur, res, tb);
        }
        
    }
    
    vector<string> letterCombinations(string digits) {
    
        vector<string> tb = {"","", "abc", "def", "ghi","jkl","mno","pqrs","tuv","wxyz"};
        vector<string> res;
    
        if (digits.size() == 0) 
            return res;
        
        string cur(digits.size() ,' ');
        helper(digits, 0, cur, res, tb);
        return res;
    }
};
