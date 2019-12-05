class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int sum;
        int min_sum = INT_MAX;
        int min_idx = -1;
        
        for (int i=0; i< gas.size(); i++) {
            sum += gas[i]-cost[i];
            if (sum < min_sum) {
                min_sum = sum;
                min_idx = i;
            }
        }
        return sum < 0 ? -1 : min_idx+1 % gas.size();
    }
};
