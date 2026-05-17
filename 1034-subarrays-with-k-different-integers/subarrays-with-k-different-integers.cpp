class Solution {
public:

    int findSubarray(vector<int> &nums,int k){

        int n = nums.size();

        unordered_map<int,int>mp;

        int count = 0;

        int left = 0;
        for(int right = 0;right<n;right++)
        {

            mp[nums[right]]++;

            while(mp.size() > k){
                mp[nums[left]]--;

                if(mp[nums[left]] == 0){
                    mp.erase(nums[left]);
                }
                left++;
            }

            count += (right-left+1);
        }

        return count;
    }
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        
        return findSubarray(nums,k) - findSubarray(nums,k-1);
    }
};