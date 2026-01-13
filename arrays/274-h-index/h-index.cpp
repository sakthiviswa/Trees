class Solution {
public:
    int hIndex(vector<int>& citations) {

        int n = citations.size();

        vector<int>dp(n+1,0);

        for(int i=0;i<n;i++){
            dp[min(citations[i],n)]++;
        }

        int tot = 0;

        for(int i=n;i>=0;i--){

            tot += dp[i];

            if(tot >= i){
                return i;
            }
        }

        return -1;

        
    }
};