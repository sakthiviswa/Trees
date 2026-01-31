class Solution {
public:
    int repeatedNTimes(vector<int>& nums) {

        unordered_map<int,int> map;

        int n = nums.size()/2;

        for(int i=0;i<nums.size();i++){
            map[nums[i]]++;

            if(map[nums[i]] == n){
                return nums[i];
            }
        }
        

        return -1;
    }
};