class Solution {
public:
    int myAtoi(string str) {
        if (str.empty()) return 0;
        int size = str.length();
        int begin = 0;

        for ( ; begin < size; ++begin) {
            if (str[begin] != ' ') {
                break;
            }
        }


        if (begin == size) return 0;

        int sign = 1;
        long long result = 0;
        if (str[begin] == '+') begin++;
        else if (str[begin] == '-') {
            sign = -1;
            begin++;
        }

        for ( ; begin < size; ++begin) {
            if (str[begin] < '0' || str[begin] > '9') return sign*result;
            result = 10*result + (str[begin] - '0');
            if (result >= INT_MAX && sign == 1) return INT_MAX;
            else if (-result <= INT_MIN && sign == -1) return INT_MIN;
        }
        return sign*result;
    }
};
