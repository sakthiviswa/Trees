class Solution {
public:
    vector<int> maxKDistinct(vector<int>& nums, int k) {
        
            sort(nums.begin(),nums.end());
            reverse(nums.begin(),nums.end());

            vector<int>res;

            res.push_back(nums[0]);
            k--;


            int rind =0;
            for(int i = 1;i<nums.size() && k>0;i++){

                if(nums[i] != res[rind]){

                    res.push_back(nums[i]);
                    k--;
                    rind++;
                   
                }
                
            }

            // 100 93 93 84 77
            // 100 93 

            return res;
    }
};