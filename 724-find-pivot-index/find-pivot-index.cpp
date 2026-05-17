class Solution {
public:
    int pivotIndex(vector<int>& nums) {

        int n = nums.size();

        vector<int>prefix;
        prefix.push_back(0);

        for(int i:nums){
            prefix.push_back(prefix.back() + i);
        }

       for(int i=0;i<n;i++){
        int leftsum = prefix[i];
        int rightsum = prefix[n] - prefix[i+1];

        if(leftsum == rightsum){
            return i;
        }
       }
       return -1;
        
    }
};