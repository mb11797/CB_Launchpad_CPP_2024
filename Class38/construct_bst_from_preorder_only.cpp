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
    
    TreeNode* bstFromPreorderHelper(vector<int>& preorder, int minV, int maxV, int &pos){
        if(pos >= preorder.size())
            return NULL;
        
        if(minV < preorder[pos] && preorder[pos] < maxV){
            TreeNode*root = new TreeNode(preorder[pos++]);

            root->left = bstFromPreorderHelper(preorder, minV, root->val, pos);
            root->right = bstFromPreorderHelper(preorder, root->val, maxV, pos);
            return root;
        }
        else{
            return NULL;
        }
    }
    
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        int pos = 0;
        TreeNode*root = bstFromPreorderHelper(preorder, INT_MIN, INT_MAX, pos);
        return root;
    }
};