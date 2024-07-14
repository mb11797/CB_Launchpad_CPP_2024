#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
Sample Input: 
15 
1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1 
*/

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

TreeNode*buildTreeFromLevelOrderInput(vector<int> input){
	if(input.size() == 0 or input[0] == -1)
		return NULL;

	queue<TreeNode*> q;
	TreeNode*root = new TreeNode(input[0]);
	q.push(root);
	int i=1;
	while(i<input.size()){
		TreeNode*frontNode = q.front();
		q.pop();

		if(input[i] != -1){
			frontNode->left = new TreeNode(input[i]);
			q.push(frontNode->left);
		}

		i++;

		if(input[i] != -1){
			frontNode->right = new TreeNode(input[i]);
			q.push(frontNode->right);
		}

		i++;
	}

	return root;
}

void iterativePreorderTraversal(TreeNode*root){
	stack<TreeNode*> stk;
	stk.push(root);

	while(!stk.empty()){
		TreeNode*topNode = stk.top();
		stk.pop();

		cout<<topNode->val<<" ";

		if(topNode->right)
			stk.push(topNode->right);
		if(topNode->left)
			stk.push(topNode->left);
	}
	cout<<endl;

	return;
}

void iterativeInorderTraversal(TreeNode*root){
	stack<TreeNode*> stk;

	while(root or !stk.empty()){
		while(root){
			stk.push(root);
			root = root->left;
		}
		root = stk.top();
		stk.pop();
		cout<<root->val<<" ";
		root = root->right;
	}
	cout<<endl;
}


int main(){
	vector<int> input;
	int n;
	cin>>n;

	for(int i=0; i<n; i++){
		int temp;
		cin>>temp;
		input.push_back(temp);
	}

	TreeNode*root = buildTreeFromLevelOrderInput(input);

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

	cout<<"Iterative Preorder Traversal: ";
	iterativePreorderTraversal(root);

	cout<<"Iterative Inorder Traversal: ";
	iterativeInorderTraversal(root);


	return 0;
}