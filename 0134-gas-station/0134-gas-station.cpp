class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int totalcost = 0;
        int totalgas = 0;

        for (int val : gas) {
            totalgas += val;
        }
        for (int val : cost) {
            totalcost += val;
        }
        if (totalgas < totalcost) {
            return -1;
        }

        int currgas = 0;
        int idx = 0;
        for (int i = 0; i < gas.size(); i++) {
            currgas += gas[i] - cost[i];
            if (currgas < 0) {
                currgas = 0;
                idx = i + 1;
            }
        }
        return idx;
    }
};