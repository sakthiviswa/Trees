class Solution {
public:
    string reversePrefix(string word, char ch) {

        int n = word.size();

        int left = 0;

        string res = "";

        if(count(word.begin(), word.end(), ch) <= 0){
            return word;
        }

        for(int right = 0;right <n;right++){



            if(word[right] == ch){
                res += word[right];
                left = right+1;

                break;

            }
            else
            {
                res += word[right];

            }
        }

        reverse(res.begin(),res.end());

        while(left < n)
        {
            res += word[left++];
        }


        return res;
        
    }
};