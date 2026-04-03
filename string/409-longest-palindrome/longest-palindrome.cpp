class Solution {
public:
    int longestPalindrome(string s) {

        unordered_map<char,int>freq;

        for(char i:s){
            freq[i]++;
        }

        int length = 0;
        bool hasodd = false;

        for(auto &i:freq){
            int count = i.second;

            length += (count / 2) * 2;

            if(count % 2 == 1){
                hasodd = true;
            }

        }
        
            if(hasodd){
                length++;
            }

        return length;
    }
};