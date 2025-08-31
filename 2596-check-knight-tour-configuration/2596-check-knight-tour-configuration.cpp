class Solution {
public:
    bool helper(vector<vector<int>>& grid,int r,int c, int expval ,int n,int l,int w) {
        if(r<0 || c<0 || r>=l || c>=w  || expval != grid[r][c]){
            return false;
        }
        if(expval == n){
           return true;
        }
        
        bool ans1=helper(grid,r-2,c+1,expval+1,n,l,w);
        bool ans2=helper(grid,r-2,c-1,expval+1,n,l,w);
        bool ans3=helper(grid,r-1,c-2,expval+1,n,l,w);
        bool ans4=helper(grid,r+1,c-2,expval+1,n,l,w);
        bool ans5=helper(grid,r-1,c+2,expval+1,n,l,w);
        bool ans6=helper(grid,r+1,c+2,expval+1,n,l,w);
        bool ans7=helper(grid,r+2,c+1,expval+1,n,l,w);
        bool ans8=helper(grid,r+2,c-1,expval+1,n,l,w);
        
        return ans1 ||ans2 ||ans3 ||ans4 ||ans5 ||ans6 ||ans7 ||ans8;
    }
    
    bool checkValidGrid(vector<vector<int>>& grid) {
        int l = grid.size();
        int w = grid[0].size();
        int n = (l*w)-1; 
        bool res =helper(grid,0,0,0,n,l,w);

        return res;
    }
};