class Solution {
public:
    void dfs_helper(int i, int j, vector<vector<char>>& grid,vector<vector<bool>>& vis, int r, int c) {
        if (i >= r || i < 0 || j >= c || j < 0 || grid[i][j] != '1' || vis[i][j] == true) {
            return;
        }
        vis[i][j]=true;

        dfs_helper(i - 1, j, grid, vis,r,c); // top
        dfs_helper(i, j - 1, grid, vis,r,c); // left
        dfs_helper(i + 1, j, grid, vis,r,c); // bottom
        dfs_helper(i, j + 1, grid, vis,r,c); // right
    }
    int numIslands(vector<vector<char>>& grid) {
        int r = grid.size();  //row
        int c = grid[0].size();  //column
        int islands = 0;
        vector<vector<bool>> vis(r, vector<bool>(c, false));
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
            if(grid[i][j]=='1' && vis[i][j] !=true){
                dfs_helper(i, j, grid, vis, r, c);
                islands++;
            }
            }
        }
        return islands;
    }
};