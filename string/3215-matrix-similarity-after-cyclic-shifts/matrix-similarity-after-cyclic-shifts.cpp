class Solution {
public:
    bool areSimilar(vector<vector<int>>& mat, int k) {

        int n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>temp(n,vector<int>(m));

        k %= m;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                if(i % 2 == 0){
                    
                  temp[i][(j+m-k)%m] = mat[i][j];
                }
                else
                {
                    temp[i][(j+k)%m] = mat[i][j];
                }
                
            }
        }

        return temp == mat;
        
    }
};