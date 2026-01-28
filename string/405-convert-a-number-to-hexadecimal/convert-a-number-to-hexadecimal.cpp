class Solution {
public:
    string toHex(int num) {

        string res = "";

       if(num == 0){
            res += "0";
            return res;
       }

       string hexa = "0123456789abcdef";

       unsigned int n = num;

        while(n > 0){

            int rev = n % 16;
            res += hexa[rev];
            n /= 16;
        }

    cout<<res;

        reverse(res.begin(),res.end());
        return res;
        
    }
};