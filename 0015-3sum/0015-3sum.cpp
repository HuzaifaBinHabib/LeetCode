class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> ans;
        sort(nums.begin(), nums.end());
        
        for (int i = 0; i < n; i++) {
            if (i > 0 && nums[i] == nums[i - 1]) {
                continue;
            }
            
            int lp = i + 1;
            int rp = n - 1;
            
            while (lp < rp) {
                int sum = nums[i] + nums[lp] + nums[rp];
                
                if (sum < 0) {
                    lp++;
                } 
                else if (sum > 0) {
                    rp--;
                } 
                else {
                    ans.push_back({nums[i], nums[lp], nums[rp]});
                    lp++;
                    rp--;
                    
                    while (lp < rp && nums[lp] == nums[lp - 1]) lp++;
                    while (lp < rp && nums[rp] == nums[rp + 1]) rp--;
                }
            }
        }
        return ans;
    }
};
