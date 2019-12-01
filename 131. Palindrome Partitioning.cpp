class Solution {
    bool is_palin(string &s, int i, int j) {
         while(i < j && s[i] == s[j]) {
           i++;
           j--;
         }
         return i >= j;
    }

    void helper(string &s, int index, vector<string> &cur, vector<vector<string>> &result) {
      if(index == s.size() && !cur.empty()) {
         result.push_back(cur);
         return;
      }

      for(int i = index; i< s.size(); i++) 
        if(is_palin(s, index, i)) {
          cur.push_back(s.substr(index, i - index + 1));
          helper(s, i+1, cur, result);
          cur.pop_back(); 
        }
}

public:
    vector<vector<string>> partition(string s) {
        if(s.empty())
            return {};
        vector<string> cur;
        vector<vector<string>> result;
        helper(s, 0, cur, result);
        return result;
    }
};
