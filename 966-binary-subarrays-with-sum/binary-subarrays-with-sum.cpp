class Solution {
public:
    int findSubarrays(vector<int>& nums,int goal){

        if(goal < 0){
            return 0;
        }

        int n = nums.size();

        int count = 0,sum = 0;

        int left = 0;
        for(int right = 0;right < n;right++){

            sum += nums[right];

            while(sum > goal){
                sum -= nums[left];
                left++;
            }   
            count += (right-left+1);
        }

        return count;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {

        return findSubarrays(nums,goal) - findSubarrays(nums,goal-1);
        
    }
};