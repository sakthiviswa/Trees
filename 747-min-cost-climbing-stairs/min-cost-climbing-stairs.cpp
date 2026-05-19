class Solution {
public:
    vector<int>dp;

    int recursion(vector<int>& cost,int n){

       

        if(n == 0 || n == 1){
            return 0;
        }

        if(dp[n] != -1){
            return dp[n];
        }


        return dp[n] = min(
            recursion(cost,n-1)+cost[n-1], 
            recursion(cost,n-2)+cost[n-2]);
    }


    int minCostClimbingStairs(vector<int>& cost) {
        int n = cost.size();

        dp.resize(n+1,-1);
        return recursion(cost,n);
    }
};