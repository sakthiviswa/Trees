class Solution {
public:
    vector<int> dp;

    int recursion(vector<int>& nums, int n) {

        if (n < 0) {
            return 0;
        }

        if (dp[n] != -1) {
            return dp[n];
        }

        return dp[n] = max(recursion(nums, n - 1),
                           recursion(nums, n - 2) + nums[n]);
    }

    int rob(vector<int>& nums) {
        int n = nums.size();

        dp.resize(n + 1, -1);

        return recursion(nums, n-1);
    }
};