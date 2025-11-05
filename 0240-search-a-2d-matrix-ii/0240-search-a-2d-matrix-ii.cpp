class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = mat.size(); int c= mat[0].size();

        int lp =0; int rp= c-1;
        while(lp < r  && rp >= 0){
            if(target == mat[lp][rp]){
                return true;
            }else if(target > mat[lp][rp]){
                lp++;
            }else{
                rp--;
            }
        }
        return false;
    }
};