#include<iostream>
#include<queue>
using namespace std;

/*
Sample Input:
7 2 4 9 1 3 12 -1
*/

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

bool searchInBST(TreeNode*root, int key){
	if(root == NULL)
		return false;

	bool found = false;
	if(key == root->val)
		found = true;
	else if(key < root->val)
		found = searchInBST(root->left, key);
	else
		found = searchInBST(root->right, key);

	return found;
}

TreeNode*deleteInBST(TreeNode*root, int key){

	if(root == NULL)
		return NULL;

	if(key < root->val){
		root->left = deleteInBST(root->left, key);
	}
	else if(key > root->val){
		root->right = deleteInBST(root->right, key);
	}
	else{
		// key == root->val
		// 0 - Child Case

		// 1 - Child Case

		// 2 - Child Case
	}

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


	cout<<"Enter the key: ";
	int keyToSearch;
	cin>>keyToSearch;

	if(searchInBST(root, keyToSearch))
		cout<<"Found the key"<<endl;
	else
		cout<<"Not Found the key"<<endl;

	return 0;
}

