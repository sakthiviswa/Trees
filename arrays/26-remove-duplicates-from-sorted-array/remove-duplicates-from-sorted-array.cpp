class Solution {
public:
    int removeDuplicates(vector<int>& nums) {

        
    

    int n = nums.size();

    if(n==0 || n==1){
        return n;
    }

    
    
        int ind=1;
        for(int i=0;i<n;i++){

            if(nums[i] != nums[ind-1]){
                nums[ind] = nums[i];
                ind++; 
            }
            
           
            
        }

        return ind;
    }
};