#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

struct bstNode
{
    int data;
    bstNode* left;
    bstNode* right;
};

bstNode* getNewNode(int val)
{
    bstNode* new_node=new bstNode();
    new_node->data=val;
    new_node->left=nullptr;
    new_node->right=nullptr;
    return new_node;
}

bstNode* Insert(bstNode* root_ptr, int val)
{
    if(root_ptr==nullptr)
    {
        root_ptr=getNewNode(val);
    }
    else if(val<=root_ptr->data) root_ptr->left=Insert(root_ptr->left,val);
    else root_ptr->right=Insert(root_ptr->right, val);
    return root_ptr;
}

bool Search(bstNode* root_ptr, int val)
{
    if(root_ptr==nullptr) return false;
    else if(root_ptr->data==val) return true;
    else if(val<root_ptr->data) return Search(root_ptr->left, val);
    else return Search(root_ptr->right, val);
}

int main()
{
    bstNode* root;
    root=nullptr;
    cout<<"Enter the number of inputs you want: ";
    int n; cin>>n;
    int temp;
    cout<<"Insert: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        root=Insert(root, temp);
    }
    cout<<"Enter the number you wanna search: ";
    int val; cin>>val;
    if(Search(root, val)) cout<<"Present!!"<<endl;
    else cout<<"Nah"<<endl;
}
