class Solution {
public:

    void dfs(vector<vector<int>> &grid,int row,int col){

        int m = grid.size();
        int n = grid[0].size();

        if(row < 0 || row >= m || col < 0 || col >= n || grid[row][col] == 0){
            return ;
        }

        
        if(grid[row][col] == 1){
            grid[row][col] = 0;
        }

        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);

        return ;

        
    }
    int numEnclaves(vector<vector<int>>& grid) {

        int m = grid.size();
        int n = grid[0].size();

        int res = 0;

         for (int i = 0; i < m; i++) {
            dfs(grid, i, 0);
            dfs(grid, i, n - 1);
        }

      
        for (int j = 0; j < n; j++) {
            dfs(grid, 0, j);
            dfs(grid, m - 1, j);
        }



        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(grid[i][j] == 1){
                    res++;
                }
            }
        }
        
        return res;
        
    }
};