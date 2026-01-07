class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        
        unordered_map<int,int>map;

        vector<int>res;

        for(int i=0;i<nums.size();i++){

            if(map.find(target-nums[i]) != map.end()){
                return {map[target-nums[i]],i};
                break;
            }
            else{
               map[nums[i]] = i;
            }
        }

        return {};
    }
};