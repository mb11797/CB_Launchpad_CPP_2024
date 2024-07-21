class Solution
{
    public:
    
    void kDistanceDownwards(struct Node *root, int k, vector<int> &ans){
        if(!root)
            return;
        
        if(k == 0){
            ans.push_back(root->data);
            return;
        }
        
        kDistanceDownwards(root->left, k-1, ans);
        kDistanceDownwards(root->right, k-1, ans);
    }
    
    // function should print the nodes at k distance from root
    vector<int> Kdistance(struct Node *root, int k)
    {
      vector<int> ans;
      
      kDistanceDownwards(root, k, ans);
      
      return ans;
    }
};