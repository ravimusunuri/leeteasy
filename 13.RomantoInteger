class Solution {
public:
    unordered_map<char, int> dict;
    int get_val(char c) {    
        this->dict.insert(
                     {
                     {'I',1}, {'V',5}, {'X',10}, 
                     {'L',50}, {'C',100}, {'D',500}, 
                     {'M',1000}
                     });
    
        auto it= this->dict.find(c);
        if (it != this->dict.end())
            return (it->second);
        else 
            return 0;
    }
    
    int romanToInt(string s) {
        int num = 0;
        int cur;
        int prev;
        for (int i=s.length()-1; i>=0; i--){
            cur = get_val(s[i]);
            prev = ( (i > 0) ? get_val(s[i-1]) : 0);
            if (prev < cur){
                num += (cur-prev);
                i--;
            } else {
                num += cur;
            }
            
        }
        return num;
    }
};
