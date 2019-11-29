class Solution {
public:
    void reverse(vector<int>& nums, int i, int j) {
        int tmp;
        while (i < j) {
            tmp = nums[i];
            nums[i] = nums[j];
            nums[j] = tmp;
            i++;
            j--;
        }
    }
    void rotate(vector<int>& nums, int k) {
        if (k > nums.size())
             k = k -nums.size();
        reverse(nums, 0, nums.size()-1);
        reverse(nums, 0, k-1);
        reverse(nums, k, nums.size()-1);
    }
};
