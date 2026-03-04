class Solution {
public:

int check(vector<vector<int>>& mat,int row,int col){

        int m = mat.size();
        int n = mat[0].size();

        for(int i=0;i<m;i++){
            if(i != row && mat[i][col] == 1){
                return 0;
            }
        }
        for(int i=0;i<n;i++){
            if( i != col && mat[row][i] == 1){
                return 0;
            }
        }

        return 1;

}
    int numSpecial(vector<vector<int>>& mat) {

        int m = mat.size();
        int n = mat[0].size();

        int count = 0;

        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){

                if(mat[i][j] == 1){

                    count += check(mat,i,j);
                }
            }
        }

        return count;
         
    }
};