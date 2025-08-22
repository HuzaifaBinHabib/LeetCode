class Solution {
public:
    void allsub(vector<int>& nums,vector<int>& ans,int i ,vector<vector<int>>& result){
        if(i==nums.size()){
            result.push_back({ans});
            return;
        }
        ans.push_back(nums[i]);
        allsub(nums,ans,i+1,result);

        ans.pop_back();
        int idx=i+1;
        while(idx<nums.size() && nums[idx]==nums[idx-1]){
            idx++;
        }
        allsub(nums,ans,idx,result);

    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
         sort(nums.begin(), nums.end()); 

         vector<int> ans;
         vector<vector<int>> result;
         allsub(nums,ans,0,result);
         return result;

    }
};