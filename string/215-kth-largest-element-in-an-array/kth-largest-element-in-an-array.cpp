class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {

        int n = nums.size();

        sort(nums.begin(),nums.end());

        for(int i=n;i>=0;i--){

            if(k <= 0){
                return nums[i];
            }
            k--;
        }

        
        return 0;
        
    }
};