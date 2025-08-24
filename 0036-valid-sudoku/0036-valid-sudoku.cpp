class Solution {
public:
    bool issafe(vector<vector<char>>& board ,int row ,int col,int dig){
        cout<<col<<endl;
        for(int i =0;i<col;i++){
            if(i!=col &&board[row][i]== dig){
                return false;
            }
        }
        for(int i =0;i<row;i++){
            if(i!=row && board[i][col]== dig){
                return false;
            }
        }
        int sr= (row/3)*3;
        int sc= (col/3)*3;
        
        for(int i =sr;i<=sr+2;i++){
        for(int j =sc;j<=sc+2;j++){
            if(i!=row && j!=col &&board[i][j]== dig){
                return false;
            }
        }
        }
        
        
        return true;
    }
    
    bool helper(vector<vector<char>>& board ,int row ,int col){
        if(row==9){
            return true;
        }
        int nextrow = row;
        int nextcol= col+1;
        if(col == 8){
            nextcol=0;
            nextrow =row+1;
        }
        if(board[row][col] == '.'){
           return  helper(board,nextrow,nextcol); 
        }
        char curentdig=board[row][col];
        if(issafe(board,row,col,curentdig)){
            if(helper(board,nextrow,nextcol)){
                return true;
            }
        }
        
        return false;
    }
    
    bool isValidSudoku(vector<vector<char>>& board) {
         bool a = helper(board,0,0);
        return a;
    }
};