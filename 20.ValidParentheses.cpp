class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        
        for(int i=0; i< s.length();i++){
            if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
                stk.push(s[i]);
            } else {
                if (stk.empty()){
                    return false;
                }
                
                char top = stk.top();
                stk.pop();
                
                if (s[i] == ']'){
                    if (top == '{' || top == '(')
                       return false;
                } else if (s[i] == '}'){
                    if (top == '[' || top == '(')
                       return false;
                } else {
                    if (top == '{' || top == '[')
                       return false;
                }
            }
        }
                
        if (!stk.empty()){
            return false;
        }
        return true;
    }
};
