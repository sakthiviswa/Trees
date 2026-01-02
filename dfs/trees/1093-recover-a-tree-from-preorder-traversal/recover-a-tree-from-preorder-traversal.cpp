/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* recoverFromPreorder(string traversal) {

        stack<TreeNode*> stk;

        int n = traversal.size();

        for(int i=0;i<n;){

            int depth = 0;

            while(i<n && traversal[i] == '-'){
                depth++;
                i++;
            }

            int value = 0;

            while(i<n && isdigit(traversal[i])){
                value = value*10 + (traversal[i]-'0');
                i++;
            }


            TreeNode* node = new TreeNode(value);

            while(stk.size() > depth){
                stk.pop();
            }

            if(!stk.empty()){
                if(!stk.top()->left){
                    stk.top()->left = node;
                }
                else{
                    stk.top()->right = node;
                }
            }

            stk.push(node);
        }

        while(1<stk.size()){
            stk.pop();
        }

        return stk.top();
        
    }
};