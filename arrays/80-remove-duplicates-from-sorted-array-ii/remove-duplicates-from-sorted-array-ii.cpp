class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        int n = nums.size();

        if(n == 0 || n == 1 || n == 2){
            return n;
        }


        int ind = 0;


        for(int i=0;i<n;i++){

            if(ind<=1 || nums[i] != nums[ind-2]){
                nums[ind] = nums[i];
                ind++;
            }
        }
        
        return ind;
    }
};