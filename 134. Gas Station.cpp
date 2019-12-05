class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        
        int min = INT_MAX;
        int minIndex = 0;
        int size = gas.size();
        int sum = 0;
        for(int i = 0; i < size; ++i) {
            sum += gas[i] - cost[i];
            if (sum < min) {
                min = sum;
                minIndex =i;
            }
        }
        
        return sum < 0 ? -1 : ((minIndex + 1) % size);
    
    }
};
