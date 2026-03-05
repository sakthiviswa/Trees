class Solution {
public:
    vector<vector<string>> solveNQueens(int n) {
        
        vector<bool>dig1(n*2,false);
        vector<bool>dig2(n*2,false);
        vector<bool>cols(n,false);

        vector<vector<string>>board;
        vector<string>cur(n,string(n,'.'));

        backtrack(0,n,dig1,dig2,cols,board,cur);

        return board;
    }

    void backtrack(int row,int n,vector<bool> &dig1,vector<bool> &dig2,
            vector<bool> &cols,vector<vector<string>> &board, vector<string> &cur){

                if(row == n){
                    board.push_back(cur);
                    return ;
                }


                for(int col = 0;col<n;col++){
                    if(cols[col] || dig1[row+col] || dig2[row-col+n-1]){
                        continue;
                    }

                    cols[col] = dig1[row+col] = dig2[row-col+n-1] = true;
                    cur[row][col]='Q';
                    backtrack(row+1,n,dig1,dig2,cols,board,cur);
                    cur[row][col]='.';
                    cols[col] = dig1[row+col] = dig2[row-col+n-1] = false;

                }

            }
};