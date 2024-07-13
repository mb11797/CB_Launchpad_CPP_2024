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

void preorder(TreeNode*root){
	if(root == NULL)
		return;
	cout<<root->val<<" ";
	preorder(root->left);
	preorder(root->right);
}

void inorder(TreeNode*root){
	if(!root)
		return;
	inorder(root->left);
	cout<<root->val<<" ";
	inorder(root->right);
}

void postorder(TreeNode*root){
	if(!root)
		return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->val<<" ";
}

void levelOrderTraversal(TreeNode*root){
	if(root == NULL)
		return;

	queue<TreeNode*> q;

	q.push(root);

	while(!q.empty()){
		TreeNode*frontNode = q.front();
		q.pop();

		cout<<frontNode->val<<" ";

		if(frontNode->left)
			q.push(frontNode->left);

		if(frontNode->right)
			q.push(frontNode->right);
	}

	return;
}

void prettyLevelOrderTraversal(TreeNode*root){
	if(root == NULL)
		return;

	queue<TreeNode*> q;
	q.push(root);
	q.push(NULL);

	while(!q.empty()){
		TreeNode*frontNode = q.front();
		q.pop();

		if(frontNode == NULL){
			cout<<endl;
			q.push(NULL);
			if(q.front() == NULL)
				break;
		}
		else{
			cout<<frontNode->val<<" ";
			
			if(frontNode->left)
				q.push(frontNode->left);

			if(frontNode->right)
				q.push(frontNode->right);
		}
	}
	return;
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

int height(TreeNode*root){
	if(!root)
		return 0;

	return 1 + max(height(root->left), height(root->right));
}

int main(){

	TreeNode*root = new TreeNode(1);
	
	root->left = new TreeNode(2);
	root->right = new TreeNode(3);

	root->left->left = new TreeNode(4);
	root->left->right = new TreeNode(5);

	root->right->right = new TreeNode(6);

	cout<<"Preorder Traversal: ";
	preorder(root);
	cout<<endl;

	cout<<"Inorder Traversal: ";
	inorder(root);
	cout<<endl;

	cout<<"Postorder Traversal: ";
	postorder(root);
	cout<<endl;

	cout<<"Level Order Traversal: ";
	levelOrderTraversal(root);
	cout<<endl;

	cout<<"Pretty Level Order Traversal: "<<endl;
	prettyLevelOrderTraversal(root);
	cout<<endl;

	cout<<"Pretty Level Order Traversal using Multi-Source BFS: "<<endl;
	prettyLevelOrderTraversal_MultiSourceBFS(root);
	cout<<endl;

	cout<<"Height: "<<height(root)<<endl;

	return 0;
}

