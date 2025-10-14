class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int maxgas = 0;
        int maxcost = 0;

        for (int i = 0; i < gas.size(); i++) {
            maxgas += gas[i];
        }
        for (int i = 0; i < cost.size(); i++) {
            maxcost += cost[i];
        }

        if (maxgas < maxcost) {
            return -1;
        }

        int currgas = 0;
        int start = 0;
        for (int i = 0; i < gas.size(); i++) {
            currgas += cost[i] - gas[i];
            if (currgas > 0) {
                currgas = 0;
                start = i + 1;
            }
        }

        return start;
    }
};