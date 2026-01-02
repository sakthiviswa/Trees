/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {

        unordered_map<TreeNode*,TreeNode*>parent;

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){

            int n = q.size();

            for(int i=0;i<n;i++){
                TreeNode* ele = q.front();

                q.pop();

                if(ele->left){
                    parent[ele->left]=ele;
                    q.push(ele->left);
                }

                if(ele->right){
                    parent[ele->right]=ele;
                    q.push(ele->right);
                }
            }


        }


        unordered_set<TreeNode*>visited;

        q.push(target);
        visited.insert(target);

        int dist = 0;

        while(!q.empty()){

            int n = q.size();

            if(dist == k)break;

            for(int i=0;i<n;i++){

                TreeNode* node = q.front();
                q.pop();


                if(node->left && !visited.count(node->left)){
                    visited.insert(node->left);
                    q.push(node->left);

                }

                if(node->right && !visited.count(node->right)){
                    visited.insert(node->right);
                    q.push(node->right);
                }

                if(parent[node] && !visited.count(parent[node])){
                    visited.insert(parent[node]);
                    q.push(parent[node]);
                }

            }

                dist++;
        }

            vector<int> res;

           while(!q.empty()){
                res.push_back(q.front()->val);
                q.pop();
           }

           return res;


        
        
    }
};