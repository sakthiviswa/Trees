class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {

        for(int row=0;row<9;row++){
            for(int col=0;col<9;col++){

                if(board[row][col] != '.'){

                    char num=board[row][col];
                    board[row][col]='.';

                    if(!isSafe(board,row,col,num)){
                        return false;
                    }

                    board[row][col]=num;
                }
            }
        }

        return true;
        
    }

    bool isSafe(vector<vector<char>>& board,int row,int col,char num){

        for(int i=0;i<9;i++){

            if(board[row][i]==num){
                return false;
            }
            if(board[i][col]==num){
                return false;
            }

            int subrow = 3* (row/3)+(i/3);
            int subcol = 3* (col/3)+(i%3);

            if(board[subrow][subcol] == num){
                return false;
            }

            
        }

        return true;
    }
};