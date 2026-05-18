class Solution {
public:
    int maxProfit(vector<int>& prices) {

        int n = prices.size();

        int max_profit = 0;

        int base = prices[0];

        for(int i=1;i<n;i++)
        {
            int cur = prices[i]-base;

            max_profit = max(max_profit,cur);

            if(prices[i] < base){
                base = prices[i];
            }
        }
        
        return max_profit;
    }
};