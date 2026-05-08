class Solution {
public:
    vector<string> generateParenthesis(int n) {
        
        vector<string>res;
        string cur;

        backtrack(0,0,n,res,cur);

        return res;
    }

    void backtrack(int openk,int closek,int n,vector<string>& res,string cur){

        if(openk == n &&  closek == n){
            res.push_back(cur);
            return;
        }

        if(n>openk){
            cur.push_back('(');
            backtrack(openk+1,closek,n,res,cur);
            cur.pop_back();
        }
        
        if(openk>closek){
            cur.push_back(')');
            backtrack(openk,closek+1,n,res,cur);
            cur.pop_back();
        }
    }


};