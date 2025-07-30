class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int curr=0;
        int maxnum= INT_MIN;
        for(int i=0; i<nums.size();i++){
             curr += nums[i];
             maxnum = max(curr,maxnum);
             if(curr<0){
                curr=0;
             }
        }
        return maxnum;
    }
};