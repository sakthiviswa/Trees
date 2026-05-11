class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq;
        int n = nums.size();
        vector<int> ans;

        for(int i=0;i<n;i++){
            while(!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }

            while(!dq.empty() && nums[dq.back()] < nums[i]) {
                dq.pop_back();
            }
            dq.push_back(i);
            if(i >= k - 1) {
                ans.push_back(nums[dq.front()]);
            }
        }
        return ans;
    }
};
        int n = nums.size();

        vector<int> res;

        deque<int> que;

        for (int i = 0; i < n; i++) {

            while (!que.empty() && que.front() <= i - k) {
                que.pop_front();
            }

            while (!que.empty() && nums[que.back()] <= nums[i]) {
                que.pop_back();
            }

            que.push_back(i);

            if (i >= k - 1) {
                res.push_back(nums[que.front()]);
            }
        }
        return res;
    }
};