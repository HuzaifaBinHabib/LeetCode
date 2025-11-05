class Solution {
public:
    bool search(vector<vector<int>>& mat, int target, int row, int col) {
        int lp = 0, rp = col - 1;
        while (lp <= rp) {
            int midcol = lp + (rp - lp) / 2;
            if (target == mat[row][midcol]) {
                return true;
            } else if (target > mat[row][midcol]) {
                lp = midcol + 1;
            } else {
                rp = midcol - 1;
            }
        }
        return false;
    }
    bool searchMatrix(vector<vector<int>>& mat, int target) {
        int r = mat.size(); int c = mat[0].size();
        int lp = 0;
        int rp = r - 1;

        while (lp <= rp) {
            int midrow = lp + (rp - lp) / 2;

            if (target >= mat[midrow][0] && target <= mat[midrow][c - 1]) {
                return search(mat, target, midrow, c);
            } else if (target >= mat[midrow][c - 1]) {
                lp = midrow + 1;
            } else {
                rp = midrow - 1;
            }
        }
        return false;
    }
};