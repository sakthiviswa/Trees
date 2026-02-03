class Solution {
public:
    int minimumCost(vector<int>& nums) {
        if(nums.size()<3) return 0;
        int ans = nums[0];
        sort(nums.begin()+1,nums.end());
        ans+= nums[1];
        ans+=nums[2];
        cout<<nums[0]<<" "<<nums[1]<<" "<<nums[2];
        return ans;
    }
};