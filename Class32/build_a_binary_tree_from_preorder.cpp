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
		this->left = NULL;
		this->right = NULL;
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

TreeNode* buildTreeFromPreorderInput(){
	int val;
	cin>>val;

	if(val == -1)
		return NULL;

	TreeNode*root = new TreeNode(val);
	root->left = buildTreeFromPreorderInput();
	root->right = buildTreeFromPreorderInput();
	return root;
}

void levelOrderTraversal(TreeNode*root){
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

	TreeNode*root = buildTreeFromPreorderInput();

	cout<<"Preorder Traversal: ";
	preorderTraversal(root);
	cout<<endl;

	cout<<"Inorder Traversal: ";
	inorderTraversal(root);
	cout<<endl;

	cout<<"Postorder Traversal: ";
	postorderTraversal(root);
	cout<<endl;

	cout<<"Level Order Traversal: "<<endl;
	levelOrderTraversal(root);
	cout<<endl;


	return 0;
}