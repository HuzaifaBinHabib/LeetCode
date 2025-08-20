class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> ans;
        int n = nums.size();
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1])
                continue;
            for (int j = i + 1; j < n; j++) {
                if (j > i + 1 && nums[j] == nums[j - 1])
                    continue;
                int lp = j + 1;
                int rp = n - 1;
                while (lp < rp) {
                   long long int sum = nums[i] + nums[j] + nums[lp] + nums[rp];
                    if (sum < target) {
                        lp++;
                    } else if (sum > target) {
                        rp--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[lp], nums[rp]});
                        lp++;
                        rp--;
                        while (lp < rp && nums[lp] == nums[lp - 1]) {
                            lp++;
                        }
                    }
                }
            }
        }
        return ans;
    }
};