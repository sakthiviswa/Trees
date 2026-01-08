class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {


        int m = grid.size();
        int n = grid[0].size();

        if(grid[0][0] != 0 || grid[m-1][n-1] != 0)return -1;

        vector<vector<int>> dir = {
            {0,1},{0,-1},{1,0},{-1,0},
            {1,1},{1,-1},{-1,-1},{-1,1}
        } ;

        queue<pair<int,int>>q;
        q.push({0,0});
        grid[0][0] = 1;

        int pathlen = 1;


        while(!q.empty()){

            int si = q.size();

            for(int i=0;i<si;i++){

                auto [r,c] = q.front();
                q.pop();

                if(r == m-1 && c == n-1){
                    return pathlen;
                }

                for(auto ele:dir){
                   int  rv = ele[0] + r;
                    int cv = ele[1] + c;

                    if( rv >= 0 && rv < m  && cv >= 0 && cv < n && grid[rv][cv] == 0 ){
                        grid[rv][cv] = 1;
                        q.push({rv,cv});
                    }
                }
            }

            pathlen++;

        }  

        return -1;


    }
};