class Solution {
public:
    bool exist(vector<vector<char>>& board, string word) {

         int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==word[0]){
                    if(dfs(board,word,i,j,0)){
                        return true;
                    }
                }
            }
        }
        
        return false;
    }

    bool dfs(vector<vector<char>>& board, string word,int row,int col, int ind){
        if (ind == word.size()) return true;

        int n=board.size();
        int m=board[0].size();

        if(row<0 || row>=n || col<0 || col>=m || board[row][col] != word[ind]){
            return false;
        }



        char temp=board[row][col];
        board[row][col]='#';

        bool found=dfs(board,word,row+1,col,ind+1) ||
                    dfs(board,word,row-1,col,ind+1) ||
                    dfs(board,word,row,col+1,ind+1) ||
                    dfs(board,word,row,col-1,ind+1) ;

        board[row][col]=temp;

        return found;

    }
};