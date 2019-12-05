class Solution {
public:
    
    void generate (int open, int close, int max, vector<string>& res, string str) {
        
        if ((open == max) && (close == max)) {
            res.push_back(str);
            return;
        }
        
        if (open < max) {
            generate(open+1, close, max, res, str+'(');
            
        }
        
        if (close < open) {
            generate(open, close+1, max, res, str+')');
        }
    }
    
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        string str="";
        generate(0, 0, n, res, str);
        return res;
    }
};
