#include<iostream>
#include<queue>
using namespace std;

/*
Sample Input:
7 2 4 9 1 3 12 -1


6 2 9 1 4 3 5 8 10 7 -1 
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
		cout<<"key == root->val"<<endl;
		// key == root->val
		// 0 - Child Case
		if(root->left == NULL and root->right == NULL){
			// cout<<"No child case"<<endl;
			return NULL;
		}
		else if(root->left != NULL and root->right == NULL){
			// 1 - Child Case
			// cout<<"1 child case"<<endl;
			TreeNode*lftNode = root->left;
			return lftNode;
		}
		else if(root->left == NULL and root->right != NULL){
			// cout<<"1 child case"<<endl;
			TreeNode*rytNode = root->right;
			return rytNode;
		}
		else{
			// 2 - Child Case
			// Steps:
			// Step1: Find Inorder Successor
			TreeNode*inorderSuccessor = root->right;
			while(inorderSuccessor->left != NULL){
				inorderSuccessor = inorderSuccessor->left;
			}

			// Step2: Replace root->val with Inorder Successor value
			root->val = inorderSuccessor->val;

			// Step3: Call delete on root->right with key = Inorder Successor value
			cout<<"Delete Inorder Succssor: "<<inorderSuccessor->val<<" | root->val: "<<root->val<<endl;
			root->right = deleteInBST(root->right, inorderSuccessor->val);
			return root;
		}
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


	cout<<"Enter the key to Search: ";
	int keyToSearch;
	cin>>keyToSearch;

	if(searchInBST(root, keyToSearch))
		cout<<"Found the key"<<endl;
	else
		cout<<"Not Found the key"<<endl;

	cout<<"Enter the key to Delete: ";
	int keyToDelete;
	cin>>keyToDelete;

	root = deleteInBST(root, keyToDelete);

	cout<<"Root: "<<root->val<<endl;

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

