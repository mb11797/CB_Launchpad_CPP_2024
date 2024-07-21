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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        if(root == NULL)
            return NULL;
        
        if(root->val == p->val or root->val == q->val){
            return root;
        }
        
        TreeNode*lftAns = lowestCommonAncestor(root->left, p, q);
        TreeNode*rytAns = lowestCommonAncestor(root->right, p, q);
        
        if(lftAns != NULL && rytAns != NULL){
            return root;
        }
        
        if(lftAns != NULL)
            return lftAns;
        
        if(rytAns != NULL)
            return rytAns;
        
        return NULL;
        // M-2
        // return lftAns != NULL ? lftAns : rytAns;
    }
};