class Solution {
public:

    vector<int>dp;

    int recursion(int n){

        if(n == 1)return 1;

        if(n == 2)return 2;

        if(dp[n] != -1){
            return dp[n];
        }

        return dp[n] = recursion(n-1) + recursion(n-2);
    }
    int climbStairs(int n) {

        dp.resize(n+1,-1);

       return recursion(n);
        
    }
};