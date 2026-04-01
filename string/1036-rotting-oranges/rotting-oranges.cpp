class Solution {
public:

    
      
    int orangesRotting(vector<vector<int>>& grid) {

        int n = grid.size();
        int m = grid[0].size();

       queue<pair<int,int>>que;

       int fresh = 0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(grid[i][j] == 2){
                    que.push({i,j});
                }
                else if(grid[i][j] == 1){
                    fresh++;
                }
            }
        }

        vector<pair<int,int>> dir = {{1,0},{0,1},{-1,0},{0,-1}};

        int min=0;

        while(!que.empty() && fresh > 0)
        {

            int q = que.size();

            for(int i=0;i<q;i++){

                auto[dx,dy] = que.front();
                que.pop();



                for(auto &[x,y]:dir){
                    int nx = dx+x;
                    int ny = dy+y;

                if(nx >= 0 && ny >= 0 && nx < n && ny < m && grid[nx][ny] == 1){
                            grid[nx][ny] = 2;
                            que.push({nx,ny});
                            fresh--;
                        }
                }

            }

                min++;

        }

            return (fresh == 0) ? min : -1;
    }

};