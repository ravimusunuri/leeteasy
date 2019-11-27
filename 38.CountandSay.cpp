class Solution {
public:
    string countAndSay(int n) {
        if (n == 0) {
            return "";
        }
        if (n==1){
            return "1";
        }
        if (n == 2) {
            return "11";
        }
        string tmp = "";
        string res = "11";
        int i = 3;
        while (i <= n) {
            tmp = "";
            int count = 1;
            int j=1;
            while (j<res.length()){
                if (res[j-1] == res[j])
                   count++;
                else {
                    tmp += count+'0';
                    tmp += res[j-1];
                    count = 1;
                }
                
                j++;
            }
            tmp += count + '0';
            tmp += res[j-1];
            i++;
            res = tmp;
        }
        res = tmp;
        return res;
    }
};
