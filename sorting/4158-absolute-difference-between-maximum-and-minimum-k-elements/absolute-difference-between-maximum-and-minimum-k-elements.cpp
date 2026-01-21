class Solution {
public:
    int absDifference(vector<int>& nums, int k) {


        int n = nums.size();

        if(n<k){
            return 0;
        }
        sort(nums.begin(),nums.end());

        int maxsum =0;

        for(int i=n-1;i>= n-k;i--){
            maxsum += nums[i];
        }

        //cout<<maxsum<<endl;
        int minsum =0;

        for(int i=0;i<k;i++){
            minsum += nums[i];
        }

        //cout<<minsum;

        return abs(maxsum-minsum);
        
    }
};