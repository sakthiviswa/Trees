class Solution {
public:
    int jump(vector<int>& nums) {

        int n = nums.size();

        if(n<=1){
            return 0;
        }
        if(nums[0] == 0){
            return -1;
        }


        int jump = 1;

        int step = nums[0];
        int maxreach = nums[0];

        for(int i = 1;i<n;i++){

            if(n-1 == i){
                return jump;
            }

            maxreach = max(maxreach,nums[i]+i);
            step--;

            if(step == 0){
                jump++;

                if(i >= maxreach){
                    return -1;
                }

                step = maxreach - i;
            }

        }

            return -1;
        
    }
};