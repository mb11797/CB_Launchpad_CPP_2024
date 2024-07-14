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

class DHPair{
public:
    int height;
    int diameter;
};

class Solution {
public:
    
    DHPair diameterOfBinaryTreeHelper(TreeNode*root){
        DHPair curDHPr;
        if(root == NULL){
            curDHPr.height = curDHPr.diameter = 0;
            return curDHPr;
        }
        
        DHPair lftDHPr = diameterOfBinaryTreeHelper(root->left);
        DHPair rytDHPr = diameterOfBinaryTreeHelper(root->right);
        
        int curHt = 1 + max(lftDHPr.height, rytDHPr.height);
        int diameter = max( lftDHPr.height + rytDHPr.height, max(lftDHPr.diameter, rytDHPr.diameter));
        
        curDHPr.height = curHt;
        curDHPr.diameter = diameter;
        
        return curDHPr;
    }
    
    int diameterOfBinaryTree(TreeNode* root) {
        DHPair pr = diameterOfBinaryTreeHelper(root);
        return pr.diameter;
    }
};









