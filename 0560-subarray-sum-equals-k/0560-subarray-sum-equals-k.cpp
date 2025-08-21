class Solution {
public:
    int subarraySum(vector<int>& nums, int target) {
        unordered_map<int, int> m;
        vector<int> ps;
        int count = 0;
        int sum = 0;
        ps.push_back(nums[0]);
        for (int i = 1; i < nums.size(); i++) {
            ps.push_back(nums[i] + ps[i - 1]);
        }
        for (int i = 0; i < ps.size(); i++) {
            if (ps[i] == target) {
                count++;
            }
            sum = ps[i] - target;
            if (m.find(sum) != m.end()) {
                count += m[sum];
            }
            m[ps[i]]++;
        }
        return count;
    }
};