class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {

        vector<int>res;

        for(int i:nums1){
            res.push_back(i);
        }

        for(int j:nums2){
            res.push_back(j);
        }


        sort(res.begin(),res.end());

        int n=res.size();

       if (n % 2 == 0) {
            return (res[n/2 - 1] + res[n/2]) / 2.0;
        } else {
            return res[n/2];
        }
        
    }
};