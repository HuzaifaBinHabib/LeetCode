class Solution {
public:
        bool searchMatrix(vector<vector<int>>& m, int target) {
        int l1=m.size();
        int l2=m[0].size();
        for(int i=0;i<l1;i++){
        int lp=0;
        int rp =l2-1;
           while(lp<=rp){
             if(m[i][lp]==target || m[i][rp]==target){
                 return true;
             }
             lp++;
             rp--;
             
           }
        }
        return false; 
    }
};