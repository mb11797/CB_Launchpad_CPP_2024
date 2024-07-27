#include<iostream>
#include<queue>
using namespace std;

class TreeNode{
public:
	int val;
	TreeNode*left;
	TreeNode*right;

	TreeNode(int val){
		this->val = val;
		left = NULL;
		right = NULL;
	}
};

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

TreeNode*insertInBST(TreeNode*&root, int val){
	if(root == NULL){
		return new TreeNode(val);
	}

	if(val <= root->val){
		root->left = insertInBST(root->left, val);
	}
	else{
		root->right = insertInBST(root->right, val);
	}

	return root;
}

TreeNode*buildBSTFromUserInput(){
	int val;
	cin>>val;

	TreeNode*root = NULL;
	while(val != -1){
		root = insertInBST(root, val);
		cin>>val;
	}
	return root;
}


int main(){
	TreeNode*root = buildBSTFromUserInput();

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

