class Solution {
public:
    void allsub(vector<int>& nums, vector<int>& ans, int i,vector<vector<int>>& result) {

        if (i == nums.size()) {
            result.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        allsub(nums, ans, i + 1, result);

        ans.pop_back();
        allsub(nums, ans, i + 1, result);
    }
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<int> ans;
        vector<vector<int>> result;
        allsub(nums, ans, 0, result);
        return result;
    }
};