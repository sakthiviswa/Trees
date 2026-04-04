class Solution {
public:
    string decodeCiphertext(string encodedText, int rows) {

        int n = encodedText.size();
        int cols = n / rows;

        vector<vector<char>>matrix(rows,vector<char>(cols));
        int ind = 0;

        for(int i=0;i<rows;i++){
            for(int j=0;j<cols;j++){
                matrix[i][j] = encodedText[ind++];
            }
        }

        string res = "";
        for(int i=0;i<cols;i++){
            int row = 0;
            int col = i;

            while(row < rows && col < cols){
                res += matrix[row][col];
                row++;
                col++;
            }

        }

        while(!res.empty() && res.back() == ' '){
            res.pop_back();
        }

        return res;

        
    }
};