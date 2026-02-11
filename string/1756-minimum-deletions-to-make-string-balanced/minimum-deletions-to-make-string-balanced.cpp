class Solution {
public:
    int minimumDeletions(string s) {

            int countB = 0;
            int deletion = 0;

            for(char c:s){

                if(c == 'b'){
                    countB++;
                }
                else
                {
                    deletion = min(deletion+1,countB);
                }
            }
        
        return deletion;
        
    }
};