class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {

        int n = nums.size();

        vector<int> result(n,0);


        for(int i=0;i<n;i++){

           int k = (i + nums[i]) % n;
           if(k < 0){
                k += n;
           }

           result[i] = nums[k];
        }


        return result;
        
    }
};