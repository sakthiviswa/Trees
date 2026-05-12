class Solution {
public:
    int countGoodSubstrings(string s) {

        int n = s.length();

        int res = 0;

        unordered_map<int,int>mp;

        int left = 0;
        for(int right = 0;right<n;right++){

            mp[s[right]]++;


            if(right-left+1 == 3){
                
                if(mp.size() == 3){
                    res++;
                }

                mp[s[left]]--;

                if(mp[s[left]] == 0)
                {
                    mp.erase(s[left]);
                }
                left++;

            }
        }

        return res;
        
    }
};