#include<iostream>
#include<queue>
using namespace std;

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

void inorder_print(node*root){
    if(root==NULL)
        return;

    inorder_print(root->left);
    cout<<root->data<<" ";
    inorder_print(root->right);
    return;
}


void bfs_awesome(node*root){
    if(root==NULL)
        return;
    queue<node*> q;
    q.push(root);
    q.push(NULL);
    while(!q.empty()){
        node*f = q.front();
        if(f==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty())
                q.push(NULL);
        }
        else{
            cout<<f->data<<" ";
            q.pop();
            if(f->left)
                q.push(f->left);
            if(f->right)
                q.push(f->right);
        }
    }
    return;
}


node*insert_in_BST(node*root, int data){
    if(root==NULL)
        return new node(data);
    if(data <= root->data){
        root->left = insert_in_BST(root->left, data);
    }
    else{
        root->right = insert_in_BST(root->right, data);
    }
    return root;
}

node*build(){
    int data;
    cin>>data;

    node*root = NULL;
    while(data != -1){
        root = insert_in_BST(root, data);
        cin>>data;
    }
    return root;
}

class LinkedList{
public:
    node*head;
    node*tail;
};

LinkedList flatten(node*root){
    LinkedList l;
    if(root == NULL){
        l.head = l.tail = NULL;
        return l;
    }

    //leaf node
    if(root->left == NULL && root->right == NULL){
        l.head = l.tail = root;
        return l;
    }

    //left is not null
    if(root->left != NULL && root->right == NULL){
        LinkedList left_LL = flatten(root->left);
        left_LL.tail->right = root;

        l.head = left_LL.head;
        l.tail = root;
        return l;
    }

    //right is not null
    if(root->right != NULL && root->left == NULL){
        LinkedList right_LL = flatten(root->right);
        root->right = right_LL.head;

        l.head = root;
        l.tail = right_LL.tail;
        return l;
    }

    //both are not null
    LinkedList left_LL = flatten(root->left);
    LinkedList right_LL = flatten(root->right);

    l.head = left_LL.head;
    left_LL.tail->right = root;
    root->right = right_LL.head;
    l.tail = right_LL.tail;

    return l;
}

int main(){
    node*root = build();
    inorder_print(root);
    cout<<endl;
    bfs_awesome(root);
    cout<<endl;

    LinkedList l = flatten(root);

    node*temp = l.head;
    while(temp!=NULL){
        cout<<temp->data<<"-->";
        temp = temp->right;
    }

    return 0;
}
