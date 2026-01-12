class Solution {
public:
    int maxProfit(vector<int>& prices) {
        
        int maxprofit = INT_MIN;

        int base = prices[0];

        for(int i=0;i<prices.size();i++){

            int cur =prices[i]-base;

            maxprofit = max(maxprofit,cur);

            if(base > prices[i]){
                base = prices[i];
            }
        }

        return maxprofit;
    }
};