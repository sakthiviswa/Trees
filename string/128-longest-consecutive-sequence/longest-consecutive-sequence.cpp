class Solution {
public:
    int longestConsecutive(vector<int>& nums) {

        int n = nums.size();

        unordered_set<int>st(nums.begin(),nums.end());

        int longest = 0;

        for(int i:st){

           

            if(st.find(i-1) == st.end()){
                int cur = i;
                int count = 1;

                while(st.find(cur+1) != st.end()){
                    cur++;
                    count++;
                }

                longest = max(longest,count);
            }
        }
        
        return longest;
    }
};