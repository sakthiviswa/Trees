class Solution {
public:
    int longestSubarray(vector<int>& nums) {

        int n = nums.size();

        vector<int>freq(2);

        int max_len = 0;
        int zeros = 0;

        int left = 0;
        for(int right = 0; right<n; right++){

            if(nums[right] == 0){
                zeros++;
            }

            while( 1 < zeros){

                if(nums[left] == 0){
                    zeros--;
                }
                left++;
            }

            max_len = max(max_len,(right-left));
        }

        return max_len;
        
    }
};