class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        vector<vector<int>> dir =
        {
            {0,1},{1,0},{0,-1},{-1,0}
        };

        queue<pair<int,int>>q;

       for(int i=0;i<m;i++){
        for(int j=0;j<n;j++){
            if(mat[i][j] == 0){
                q.push({i,j});
            }
            else{
                mat[i][j] = INT_MAX;
            }
        }
       }

        

        while(!q.empty()){

            auto [r,c] = q.front();
            q.pop();

            

            

            for(auto ele:dir){
                int row = r + ele[0];
                int col = c + ele[1];

                if(row >= 0 && row < m && col >= 0 && col < n){
                    if(mat[row][col] > mat[r][c]+1){
                        mat[row][col] = mat[r][c]+1;
                        q.push({row,col});
                    }
                }
            }


        }

        return mat;
        
    }
};