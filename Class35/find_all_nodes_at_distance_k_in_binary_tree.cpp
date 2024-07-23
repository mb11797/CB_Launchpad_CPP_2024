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
    
    void findAllNodesAtKDistanceDownwards(TreeNode *root, int k, vector<int> &ans){
        if(!root)
            return;
        
        if(k == 0){
            ans.push_back(root->val);
            return;
        }
        
        findAllNodesAtKDistanceDownwards(root->left, k-1, ans);
        findAllNodesAtKDistanceDownwards(root->right, k-1, ans);
    }
    
    int findAllNodesAtDistK(TreeNode* root, TreeNode* target, int k, vector<int> &ans){
        if(!root){
            return -1;
        }
        
        if(root->val == target->val){
            findAllNodesAtKDistanceDownwards(root, k, ans);
            return 0;
        }
        
        int dLeft = findAllNodesAtDistK(root->left, target, k, ans);
        if(dLeft != -1){
            if(dLeft + 1 == k){
                // ancestor node
                ans.push_back(root->val);
            }
            else{
                findAllNodesAtKDistanceDownwards(root->right, k - (dLeft+1) - 1, ans);
            }
            
            return dLeft + 1;
        }
        
        int dRight = findAllNodesAtDistK(root->right, target, k, ans);
        if(dRight != -1){
            if(dRight + 1 == k){
                // ancestor node
                ans.push_back(root->val);
            }
            else{
                findAllNodesAtKDistanceDownwards(root->left, k - (dRight+1) - 1, ans);
            }
            
            return dRight + 1;
        }
        
        return -1;
    }
    
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> ans;
        
        findAllNodesAtDistK(root, target, k, ans);
        
        return ans;
    }    
};