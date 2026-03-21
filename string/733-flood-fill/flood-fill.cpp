class Solution {
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {

        int oldcolor = image[sr][sc];

        if(oldcolor != color){
            dfs(sr,sc,oldcolor,color,image);
        }
        return image;
        
    }

    void dfs(int r,int c,int oldcolor,int newcolor,vector<vector<int>> &image){

        int n = image.size();
        int m = image[0].size();

        if(r < 0 || r >= n || c < 0 || c >= m || image[r][c] != oldcolor){
            return ;
        }

        image[r][c] = newcolor;

        dfs(r+1,c,oldcolor,newcolor,image);
        dfs(r-1,c,oldcolor,newcolor,image);
        dfs(r,c+1,oldcolor,newcolor,image);
        dfs(r,c-1,oldcolor,newcolor,image);
    }
};