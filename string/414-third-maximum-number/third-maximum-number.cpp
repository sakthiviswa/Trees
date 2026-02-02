class Solution {
public:
    int thirdMax(vector<int>& nums) {

        sort(nums.begin(),nums.end());
        reverse(nums.begin(),nums.end());

        nums.erase(unique(nums.begin(),nums.end()),nums.end());

        if(nums.size() == 1){
            return nums[0];
        }

        if(nums.size() == 2){
            return max(nums[1],nums[0]);
        }

        
        return nums[2];
        
        
    }
};