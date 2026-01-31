class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int n = letters.size();

        char res = ' ';

        for(char c:letters){

            if(target < c){
                res = c;
                break;
            }
        }

        if(res == ' '){
            res = letters[0];
        }

        return res;
        
    }
};