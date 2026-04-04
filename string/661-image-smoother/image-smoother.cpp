class Solution {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>>& img) {

        int n = img.size();
        int m = img[0].size();

        vector<vector<int>> res(n,vector<int>(m,0));

        vector<pair<int,int>>dir = {
            {-1,-1},{0,-1},{1,-1},
            {-1,0},{0,0},{1,0},
            {-1,1},{0,1},{1,1}
        };

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){

                int sum = 0;
                int count = 0;

                for(auto &d:dir){
                    int x = d.first+i;
                    int y = d.second+j;


                    if(0 <= x && x < n && y >= 0 && y < m){
                        sum += img[x][y];
                        count++;
                    }
                }

                res[i][j] = sum / count;
            }
        }
        

        return res;
    }
};