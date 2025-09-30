class Solution {
public:
    int helper(vector<int>& arr, int tar, int s, int e) {
        if (s <= e) {
            int mid = s + (e - s) / 2;
            if (tar == arr[mid]) {
                return mid;
            } else if (tar >= arr[mid]) {
                return helper(arr, tar, mid + 1, e);
            } else {
                return helper(arr, tar, s, mid - 1);
            }
        }
        return -1;
    }
    int search(vector<int>& nums, int target) {
        int s = 0;
        int e = nums.size();

        return helper(nums, target, s, e);
    }
};