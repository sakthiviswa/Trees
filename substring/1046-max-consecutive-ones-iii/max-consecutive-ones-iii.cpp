class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {

        int n = nums.size();

        vector<int>freq(2);

        int max_freq = 0;
        int max_len = 0;

        int left = 0;
        for(int right = 0;right<n;right++){
            freq[nums[right]]++;
            //max_freq = max(max_freq,freq[nums[right]]);

            while( k < freq[0]){
                
                    freq[nums[left]]--;

                left++;
            }

            max_len = max(max_len,(right-left+1));
        }
        
        return max_len;
    }
};