class Solution {
public:
    bool isValid(string s) {

        unordered_map<char,char> map =
        {

            {'}','{'},
            {'>','<'},
            {']','['},
            {')','('}
        };


        stack<char> stk;

        for(char c:s){

            if(c == '(' || c == '{' || c == '[' || c == '<')
            {
                stk.push(c);
            }
            else 
            {   
               
                if(stk.empty() || stk.top() != map[c]){
                    return false;
                }

                stk.pop();
            }
        }
        return stk.empty();
        
    }
};