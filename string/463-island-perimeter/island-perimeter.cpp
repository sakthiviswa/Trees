class Solution {
public:
    int dfs(int row,int col,vector<vector<int>> &grid)
    {
      int n = grid.size();
      int m = grid[0].size();

      if(row < 0 || row >= n || col < 0 || col >= m ){
        return 1;
      }

       if(grid[row][col] == 0)
            return 1;

      
        if(grid[row][col] == 2)
            return 0;

      grid[row][col] = 2;

      int r = dfs(row-1,col,grid);
      int l = dfs(row+1,col,grid);
      int t = dfs(row,col+1,grid);
      int b = dfs(row,col-1,grid);

      return r+l+t+b;


    }
    int islandPerimeter(vector<vector<int>>& grid) {
        
      int n = grid.size();
      int m = grid[0].size();

      int count = 0;

      for(int i=0;i<n;i++)
      {
        for(int j=0;j<m;j++){

            if(grid[i][j] == 1){
                count = dfs(i,j,grid);
            }
        }
      } 

      return count;
    }
};