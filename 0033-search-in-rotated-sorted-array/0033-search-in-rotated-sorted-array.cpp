class Solution {
public:
    int search(vector<int>& nums, int target) {
        int lp = 0;
        int rp = nums.size() - 1;
        int mid = 0;
        while (lp <= rp) {
            mid = lp + (rp - lp) / 2;
            if (nums[mid] == target) {
                return mid;
            }
            if (nums[lp] <= nums[mid]) {
                if (nums[lp] <= target && target <= nums[mid]) {
                    rp = mid - 1;
                } else {
                    lp = mid + 1;
                }
            } else {
                if (target <= nums[rp] && nums[mid] <= target) {

                    lp = mid + 1;
                }

                else {
                    rp = mid - 1;
                }
            }
        }
                return -1;
        }
        };