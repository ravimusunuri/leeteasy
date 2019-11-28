class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int size = digits.size();
        int j = size-1;
        int carry = 1;
        int num = 0;
        while (j >=0) {
            num = digits[j];
            num += (carry);
            carry = num/10;
            digits[j] = (num % 10);
            j--;
        }
        if (carry) {
            auto it = digits.begin();
            digits.insert(it, carry);
        }
        return digits;
    }
};
