class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {

        unordered_map<int,int> mp;

        mp[0] = 1;

        int sum = 0;
        int count = 0;

        for(int num : nums){

            // current prefix sum
            sum += num;

            // check required prefix
            if(mp.find(sum-k) != mp.end()){
                count += mp[sum-k];
            }

            // store current prefix
            mp[sum]++;
        }

        return count;
    }
};