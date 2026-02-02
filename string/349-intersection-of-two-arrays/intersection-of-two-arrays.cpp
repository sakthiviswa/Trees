class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {

        vector<int> res;


        for(int i:nums1){
            for(int j:nums2){
                if(i == j){
                    res.push_back(i);
                    break;
                }
            }
        }

        sort(res.begin(),res.end());
        res.erase(unique(res.begin(),res.end()),res.end());

        return res;
        
    }
};