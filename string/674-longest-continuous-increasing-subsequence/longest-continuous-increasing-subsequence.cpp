class Solution {
public:
    int findLengthOfLCIS(vector<int>& arr) {
        int n = arr.size();

        int count = 1;
        int maxLen = 1;

        for(int i=1;i<n;i++){
            if(arr[i-1] < arr[i]){
                count++;
            }
            else 
            {   
                count = 1;
            }

            maxLen = max(maxLen,count);
        }

        return maxLen;
        
    }
};