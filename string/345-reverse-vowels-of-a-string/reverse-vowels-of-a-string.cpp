class Solution {
public:
    string reverseVowels(string str) {

        stack<char> stk;

        int n = str.size();

        for(int i=0;i<n;i++){
            if(
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
                str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            )
            {
                stk.push(str[i]);
            }
        }


        string res = "";

        for(int i=0;i<n;i++){

            if(
                str[i] == 'A' || str[i] == 'E' || str[i] == 'I' || str[i] == 'O' || str[i] == 'U' ||
                str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u'
            )
            {

                res += stk.top();
                stk.pop();


            }
            else
            {

                res += str[i];
            }
        }


        return res;
        
    }
};