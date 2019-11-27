class Solution {
public:
    
    bool isPrefixMatch(vector<string>& strs, int start, int end) {
        for (int i=0; i<strs.size();i++){
             for (int j=start; j<=end;j++){
                if (strs[0][j] != strs[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }
    
    string longestCommonPrefix(vector<string>& strs) {
        int min_len = INT_MAX;
        
        if (strs.size() ==0){
            return "";
        }
        if (strs.size() == 1){
            return strs[0];
        }
        for (int i=0; i<strs.size(); i++){
            if(min_len > strs[i].length())
                min_len = strs[i].length(); 
        }
        
        int low = 0;
        int high = min_len -1;
        string prefix="";
        int mid, match;
        
        while (low <= high){
            mid = (low+high)/2;
            match = isPrefixMatch(strs, low, mid);
            if (match == true) {
                prefix = prefix + strs[0].substr(low,mid-low+1);
                low = mid+1;
            }  else {
                high = mid-1;
            }
            
        }
        return prefix;
    }
};
