class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> s;
        int first, second, result;
        for(auto i : tokens){
            if(i.size() == 1 && (i[0] == '+' || i[0] == '-' || i[0] == '*' || i[0] == '/')){
                first = s.top();
                s.pop();
                second = s.top();
                s.pop();
                if(i[0] == '+') result = first + second;
                if(i[0] == '-') result = second - first;
                if(i[0] == '*') result = first * second;
                if(i[0] == '/') result = second / first;
                s.push(result);
            } else{
                s.push(stoi(i));
            }
        }
        return s.top();
    }
};
