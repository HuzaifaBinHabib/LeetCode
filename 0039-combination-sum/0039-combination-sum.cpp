class Solution {
public:
    set<vector<int>> s;
    void cs(vector<int>& arr,int i, int tar,vector<vector<int>>& ans,vector<int>& combin){
        int n = arr.size();
        if(i==n || tar <0){
            return;
        }
        if(tar == 0 ){
            if(s.find(combin)==s.end()){
            ans.push_back(combin);
            s.insert(combin);
            }
            return;
        }
        combin.push_back(arr[i]);
        cs(arr,i,tar-arr[i],ans,combin);
        cs(arr,i+1,tar-arr[i],ans,combin);
        combin.pop_back();
        cs(arr,i+1,tar,ans,combin);
        
    }
    vector<vector<int>> combinationSum(vector<int>& arr, int tar) {
       vector<vector<int>> ans;
       vector<int>combin;
       cs(arr,0,tar,ans,combin);   
       return ans;
    }
};