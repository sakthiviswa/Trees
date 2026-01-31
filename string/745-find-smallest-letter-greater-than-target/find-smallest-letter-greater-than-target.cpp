class Solution {
public:
    char nextGreatestLetter(vector<char>& letters, char target) {

        int n = letters.size();

        char res = letters[0];

        for(char c:letters){

            if(target < c){
                res = c;
                break;
            }
        }

       

        return res;
        
    }
};