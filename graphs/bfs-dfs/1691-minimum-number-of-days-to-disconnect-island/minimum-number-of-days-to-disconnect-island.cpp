class Solution {
public:

    void dfs(vector<vector<int>>& grid,int row,int col){

         int m= grid.size();
        int n= grid[0].size();

        if(row<0 || row >=m || col<0 || col>=n || grid[row][col] == 0){
            return ;
        }

        grid[row][col] = 0;

        dfs(grid,row+1,col);
        dfs(grid,row-1,col);
        dfs(grid,row,col+1);
        dfs(grid,row,col-1);
        
        return ;
    }

    int countisland(vector<vector<int>>grid){
         int m= grid.size();
        int n= grid[0].size();


        int cnt=0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    cnt++;
                    dfs(grid,i,j);
                }
            }
        }

        return cnt;

    }
    int minDays(vector<vector<int>> grid) {

        int m= grid.size();
        int n= grid[0].size();

        if (countisland(grid) != 1) return 0;
       

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(grid[i][j] == 1){
                    grid[i][j] = 0;
                    if(countisland(grid) != 1)return 1;
                    grid[i][j] = 1;
                }
            }
        }

        return 2;
        
    }
};