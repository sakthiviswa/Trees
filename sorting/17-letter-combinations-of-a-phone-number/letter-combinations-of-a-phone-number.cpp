class Solution {
public:
     
unordered_map<char, string> phoneNumber = {
    {'0', ""},
    {'1', ""},
    {'2', "abc"},
    {'3', "def"},
    {'4', "ghi"},
    {'5', "jkl"},
    {'6', "mno"},
    {'7', "pqrs"},
    {'8', "tuv"},
    {'9', "wxyz"}
};
    vector<string> letterCombinations(string digits) {

        if(digits.size() == 0){
            return {};
        }

        string temp = "";
        vector<string> res;

        backtrack(digits,temp,res,0);

        return res;

      
    }

    void backtrack(string digits,string& cur,vector<string>& res,int ind){

        if(cur.size() == digits.size()){
            res.push_back(cur);
            return;
        }

        string letters = phoneNumber[digits[ind]];

        for(char i:letters){

            cur.push_back(i);
            backtrack(digits,cur,res,ind+1);

            cur.pop_back();
            
        }


        return;

    }
       

    
};