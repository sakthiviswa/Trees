class Solution {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>>& mat, int r, int c) {

        int  n = mat.size();
        int m = mat[0].size();

        vector<vector<int>>res(r,vector<int>(c));

          if(n * m != r * c) return mat;
          int ind = 0;

        for(int i=0;i<mat.size();i++){
            for(int j=0;j<mat[0].size();j++){
                res[ind / c][ind % c] = mat[i][j];
                ind++;
            }
        }

        return res;
        
    }
};