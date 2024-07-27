#include<iostream>
#include<unordered_map>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode*left;
	TreeNode*right;

	TreeNode(int val){
		this->val = val;
		this->left = NULL;
		this->right = NULL;
	}
};

TreeNode*buildTreeFromPreorderAndInorder(int preorder[], int inorder[], int beg, int en, int &preorderIdx){

	if(beg > en)
		return NULL;

	// Preorder Fashion -> Calls

	TreeNode*root = new TreeNode(preorder[preorderIdx]);
	preorderIdx++;

	// rootIdx = ???????
	int rootIdxInInorder;
	for(int i=beg; i<=en; i++){
		if(inorder[i] == root->val){
			rootIdxInInorder = i;
			break;
		}
	}

	root->left = buildTreeFromPreorderAndInorder(preorder, inorder, beg, rootIdxInInorder-1, preorderIdx);
	root->right = buildTreeFromPreorderAndInorder(preorder, inorder, rootIdxInInorder+1, en, preorderIdx);
	return root;
}

TreeNode*buildTreeFromPreorderAndInorder_usingStaticVariable(int preorder[], int inorder[], int beg, int en){
	static int preorderIdx = 0;

	if(beg > en)
		return NULL;

	// Preorder Fashion -> Calls

	TreeNode*root = new TreeNode(preorder[preorderIdx]);
	preorderIdx++;

	// rootIdx = ???????
	int rootIdxInInorder;
	for(int i=beg; i<=en; i++){
		if(inorder[i] == root->val){
			rootIdxInInorder = i;
			break;
		}
	}

	root->left = buildTreeFromPreorderAndInorder_usingStaticVariable(preorder, inorder, beg, rootIdxInInorder-1);
	root->right = buildTreeFromPreorderAndInorder_usingStaticVariable(preorder, inorder, rootIdxInInorder+1, en);
	return root;
}

TreeNode*buildTreeFromPreorderAndInorder_Optimized(int preorder[], int inorder[], int beg, int en, unordered_map<int, int> elmtVsInorderIdx){
	static int preorderIdx = 0;

	if(beg > en)
		return NULL;

	// Preorder Fashion -> Calls

	TreeNode*root = new TreeNode(preorder[preorderIdx]);
	preorderIdx++;


	int rootIdxInInorder;
	// rootIdx = ???????
	/*
	// Takes O(N) Time -> So use elmtVsInorderIdx
	for(int i=beg; i<=en; i++){
		if(inorder[i] == root->val){
			rootIdxInInorder = i;
			break;
		}
	}
	*/
	rootIdxInInorder = elmtVsInorderIdx[root->val];


	root->left = buildTreeFromPreorderAndInorder_Optimized(preorder, inorder, beg, rootIdxInInorder-1, elmtVsInorderIdx);
	root->right = buildTreeFromPreorderAndInorder_Optimized(preorder, inorder, rootIdxInInorder+1, en, elmtVsInorderIdx);
	return root;
}

void preorderTraversal(TreeNode*root){
	if(!root)
		return;
	cout<<root->val<<" ";
	preorderTraversal(root->left);
	preorderTraversal(root->right);
}

void inorderTraversal(TreeNode*root){
	if(!root)
		return;
	inorderTraversal(root->left);
	cout<<root->val<<" ";
	inorderTraversal(root->right);
}

void postorderTraversal(TreeNode*root){
	if(!root)
		return;
	postorderTraversal(root->left);
	postorderTraversal(root->right);
	cout<<root->val<<" ";
}

void prettyLevelOrderTraversal_MultiSourceBFS(TreeNode*root){
	if(root == NULL)
		return;

	// Multi-Source BFS
	queue<TreeNode*> q;
	q.push(root);

	while(!q.empty()){
		int sz = q.size();

		for(int i=0; i<sz; i++){
			TreeNode*frontNode = q.front();
			q.pop();

			cout<<frontNode->val<<" ";

			if(frontNode->left)
				q.push(frontNode->left);

			if(frontNode->right)
				q.push(frontNode->right);
		}
		cout<<endl;
	}

	return;
}


int main(){
	int preorder[8] = {1,2,4,5,6,7,3,8};
	int inorder[8] = {4,2,6,5,7,1,3,8};
	int n = 8;
	int preorderIdx = 0;

	unordered_map<int, int> elmtVsInorderIdx;
	for(int i=0; i<n; i++)
		elmtVsInorderIdx[inorder[i]] = i;


	// TreeNode*root = buildTreeFromPreorderAndInorder(preorder, inorder, 0, n-1, preorderIdx);
	// TreeNode*root = buildTreeFromPreorderAndInorder_usingStaticVariable(preorder, inorder, 0, n-1);
	TreeNode*root = buildTreeFromPreorderAndInorder_Optimized(preorder, inorder, 0, n-1, elmtVsInorderIdx);


	cout<<"Preorder Traversal: "<<endl;
	preorderTraversal(root);
	cout<<endl;

	cout<<"Inorder Traversal: "<<endl;
	inorderTraversal(root);
	cout<<endl;

	cout<<"Postorder Traversal: "<<endl;
	postorderTraversal(root);
	cout<<endl;

	cout<<"Level Order Traversal: "<<endl;
	prettyLevelOrderTraversal_MultiSourceBFS(root);
	cout<<endl;

	return 0;
}


