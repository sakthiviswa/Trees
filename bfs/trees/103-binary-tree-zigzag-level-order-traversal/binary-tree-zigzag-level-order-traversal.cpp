class Solution {
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;

        if (!root) return res;

        queue<TreeNode*> q;
        q.push(root);

        bool reachedlevel = true;

        while (!q.empty()) {
            int levelsize = q.size();
            vector<int> arr(levelsize); 

            for (int i = 0; i < levelsize; i++) {
                TreeNode* ele = q.front();
                q.pop();

                int index = reachedlevel ? i : (levelsize - 1 - i);
                arr[index] = ele->val;

                if (ele->left) {
                    q.push(ele->left);
                }
                if (ele->right) {
                    q.push(ele->right);
                }
            }

            res.push_back(arr);
            reachedlevel = !reachedlevel;
        }

        return res;
    }
};
