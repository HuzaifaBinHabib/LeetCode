class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int tar) {
        int n = nums.size();
        vector<vector<int>> ans;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }

            for (int j = i + 1; j < n; j++) {
                if (j > i+1 && nums[j] == nums[j - 1]) {
                    continue;
                }
                int lp = j + 1;
                int rp = n - 1;
                while (lp < rp) {
                    long long sum = (long long)nums[i] + nums[j] + nums[lp] + nums[rp];
                    if (sum < tar) {
                        lp++;
                    } else if (sum > tar) {
                        rp--;
                    } else {
                        ans.push_back({nums[i], nums[j], nums[lp], nums[rp]});
                        lp++, rp--;
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