class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {

        int n = cardPoints.size();

        int totalSum = 0;
        for(int i:cardPoints){
            totalSum += i;
        }
        if(n == k)return totalSum;

        int windowSize = n - k;

        int res = INT_MAX;
        int sum = 0;

        int left = 0;
        for(int right = 0;right<n;right++){

            sum += cardPoints[right];

            if(right-left+1 == windowSize){
                res = min(sum,res);

                sum -= cardPoints[left];
                left++;
            }
        }
        return totalSum-res;
    }
};