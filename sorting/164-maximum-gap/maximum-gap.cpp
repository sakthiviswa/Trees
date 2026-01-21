class Solution {
public:
    int maximumGap(vector<int>& nums) {

        int n = nums.size();
        //cout<<n;

        if(n<2){
            return 0;
        }

        sort(nums.begin(),nums.end());

        int diff=0;

        int maxele = 0;

        for(int i=1;i<n;i++){

            diff = nums[i]-nums[i-1];

            maxele = max(maxele,diff);

            
        }

        return maxele;
        
    }
};