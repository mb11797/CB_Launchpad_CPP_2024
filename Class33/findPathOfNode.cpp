#include<iostream>
#include<queue>
#include<stack>
using namespace std;

/*
Sample Input -> Level Order Input: 
15 
1 2 3 4 5 -1 -1 -1 -1 6 7 -1 -1 -1 -1 

Sample Input -> Preorder Input: 
1 2 4 -1 -1 5 6 -1 -1 7 -1 -1 3 -1 -1
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

bool isSymmetricHelper(TreeNode*a, TreeNode*b){
	if(a == NULL && b == NULL){
		return true;
	}

	if(a == NULL or b == NULL){
		return false;
	}

	if(a->val != b->val){
		return false;
	}

	return isSymmetricHelper(a->left, b->right) && isSymmetricHelper(a->right, b->left);
}

bool isSymmetric(TreeNode*root){
	if(root == NULL){
		return true;
	}

	if(root->left == NULL && root->right == NULL)
		return true;

	return isSymmetricHelper(root->left, root->right);
}

bool findNode(TreeNode*root, int destNode){
	if(root == NULL){
		return false;
	}

	if(root->val == destNode){
		return true;
	}

	return findNode(root->left, destNode) or findNode(root->right, destNode);
}

bool findPathRec(TreeNode*root, int destNode, string &path){
	if(root == NULL){
		return false;
	}

	if(root->val == destNode){
		path.push_back((char)('0' + root->val));
		return true;
	}

	path.push_back((char)('0' + root->val));
	if(findPathRec(root->left, destNode, path)){
		return true;
	}

	if(findPathRec(root->right, destNode, path)){
		return true;
	}
	path.pop_back();
	return false;
}

string findPath(TreeNode*root, int destNode){
	string path = "";
	if(root == NULL)
		return path;

	findPathRec(root, destNode, path);
	return path;
}

int main(){
	// vector<int> input;
	// int n;
	// cin>>n;

	// for(int i=0; i<n; i++){
	// 	int temp;
	// 	cin>>temp;
	// 	input.push_back(temp);
	// }

	// TreeNode*root = buildTreeFromLevelOrderInput(input);

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

	cout<<"Is Symmetric: "<<(isSymmetric(root) ? "Yes" : "No")<<endl;

	cout<<"Find Node ";
	int nodeVal;
	cin>>nodeVal;
	cout<<nodeVal<<" : "<<(findNode(root, nodeVal) ? "Found" : "Not Found")<<endl;

	cout<<"Find Path "<<nodeVal<<" : "<<findPath(root, nodeVal)<<endl;

	return 0;
}