class Solution {
public:
    void swap(vector<int>& nums, int i, int j) {
        int tmp = nums[i];
        nums[i] = nums[j];
        nums[j] = tmp;
    }

    void sortColors(vector<int>& nums) {
       int low = 0;
        int high = nums.size()-1;
        int mid = 0;

        while (mid <= high) {
           switch(nums[mid]) {
                case 0:
                        swap(nums, low, mid);
                        low++;
                        mid++;
                        break;
                case 1:
                        mid++;
                        break;
                case 2:
                        swap(nums, mid, high);
                        high--;
                        break;
           }
        }
    }
};
