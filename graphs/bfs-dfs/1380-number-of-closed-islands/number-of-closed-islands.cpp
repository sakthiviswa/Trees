class Solution {
public:

    
    bool dfs(vector<vector<int>>& grid,int row,int col){

        int m=grid.size();
        int n=grid[0].size();

        if(row < 0 || row >= m || col<0 || col >= n ){
            return false;
        }

        if(grid[row][col] != 0){
            return true;
        }

        grid[row][col] = 2;

        bool up = dfs(grid,row+1,col);
        bool down =  dfs(grid,row-1,col);
        bool right =  dfs(grid,row,col+1);
        bool left =  dfs(grid,row,col-1);

        return up && down && right && left;
            


    }
    int closedIsland(vector<vector<int>>& grid) {

        int m=grid.size();
        int n=grid[0].size();

        int res=0;
    
       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j] == 0){

                if(dfs(grid,i,j)){
                    res ++;
                }
              
            }
            
        }
       } 

       return res;
    }
};