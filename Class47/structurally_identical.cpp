#include<iostream>
using namespace std;

//10 true 20 true 40 false false true 50 false false true 30 true 60 false false true 73 false false

/*
When we say structurally identical trees, we mean that both the trees have exactly the same number of nodes, arranged in the exactly same way. It is not necessary that the value of each node should also be the same.

Since, we need to traverse each node of the tree and each node has the same property of having a data value, a left child and a right child, we will proceed with the method of recursion.

The algorithm we will follow will be therefore:-

If both trees are NULL, return true.
If both trees are not NULL, then compare data and recursively check left and right sub-tree structures.
*/


class node{
public:
    int data;
    node*left;
    node*right;

    node(int d){
        data = d;
        left = NULL;
        right = NULL;
    }
};

node*build(){
    int data;
    cin>>data;

    node*root = new node(data);

    string left, right;

    cin>>left;
    if(left == "true")
        root->left = build();

    cin>>right;
    if(right == "true")
        root->right = build();

    return root;
}

bool are_structurally_identical(node*root_1, node*root_2){
    //base case
    if(root_1 == NULL && root_2 == NULL)
        return true;

    if(root_1 == NULL || root_2 == NULL)
        return false;

    //Recursive case
    return (are_structurally_identical(root_1->left, root_2->left) && are_structurally_identical(root_1->right, root_2->right));
}

int main(){
    node*root_1 = build();
    node*root_2 = build();

    if(are_structurally_identical(root_1, root_2))
        cout<<"true"<<endl;
    else
        cout<<"false"<<endl;


    return 0;
}




