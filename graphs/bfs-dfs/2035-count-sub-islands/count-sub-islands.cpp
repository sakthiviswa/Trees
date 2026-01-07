class Solution {
public:

    bool dfs(vector<vector<int>>& grid1,vector<vector<int>>& grid2,int row,int col){

        int m = grid2.size();
        int n = grid2[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n){
            return true;
        }
        
        if(grid2[row][col] == 0){
            return true;
        }

        bool sub = (grid1[row][col] == 1);

        grid2[row][col] = 0;

        bool up = dfs(grid1,grid2,row+1,col);
        bool down = dfs(grid1,grid2,row-1,col);
        bool right = dfs(grid1,grid2,row,col+1);
        bool left = dfs(grid1,grid2,row,col-1);

        return sub && up && down && left && right;
    }
    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {

        int m = grid1.size();
        int n = grid1[0].size();


        int res =0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid2[i][j] == 1){

                    if(dfs(grid1,grid2,i,j)){
                        res++;
                    }

                }
            }
        }
        
        return res;
    }
};