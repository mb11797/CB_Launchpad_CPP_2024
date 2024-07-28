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
    
    bool isValidBSTHelper(TreeNode*root, long minV=LONG_MIN, long maxV=LONG_MAX){
        
        if(root == NULL){
            return true;
        }
        
        if(!(minV < root->val and root->val < maxV)){
            return false;
        }
        
        return isValidBSTHelper(root->left, minV, root->val) and isValidBSTHelper(root->right, root->val, maxV);
    }
    
    bool isValidBST(TreeNode* root) {        
        return isValidBSTHelper(root);
    }
};