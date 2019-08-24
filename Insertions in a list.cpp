#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

class Node
{
public:
    int data;
    Node* next;
};

/*void removeDuplicates(Node* head)
{
    Node* temp;
    if(head==nullptr)
        return;
    if(head->next!=nullptr)
    {
        if(head->data==head->next->data) //if repeating element is found
        {
            temp=head->next; //stores the duplicate node temporarily
            head->next=head->next->next; //head's next points to the list two nodes later
            free(temp); //free the temporary node
            removeDuplicates(head); //recurse
        }
        else removeDuplicates(head->next);
    }

}*/


//adding nodes to beginning
// a reference (pointer to pointer) to the head of a list to insert at the head of the list
void push(Node** head_ref,int data)
{
    Node* new_node= new Node(); //allocates node sized memory;
    new_node->data=data; //inserts data;
    new_node->next=*head_ref; //points to where head pointer was pointing, i.e., makes next of new_node as head;
    (*head_ref)=new_node; //makes head point to new_node;
}

//earlier we had "**" as it was a pointer to a pointer. But now we are pointing to a node;
void insertAfter(Node* prev_node,int data)
{
    //check that previous node isn't null!
    if(prev_node==nullptr)
    {
        cout<<"Previous node is null! \n";
        return;
    }
    Node* new_node= new Node();
    new_node->data=data;
    new_node->next=prev_node->next; //make it point to node after previous node
    prev_node->next=new_node; //make previous node point to new node
}

void append(Node** head_ref, int data)
{
    Node* new_node=new Node();
    Node *last=(*head_ref);
    new_node->data=data;
    new_node->next=nullptr;
    if(*head_ref==nullptr)
    {
        *head_ref=new_node;
        return;
    }
    while(last->next!=nullptr)
    {
        last=last->next;
    }
    last->next=new_node;
    return;
}

void printList(Node *node)
{
    while(node!=nullptr)
    {
        cout<<node->data<<" ";
        node=node->next;
    }
    cout<<"\n";
}

int main()
{
    Node* head;
    head=nullptr;
    cout<<"Enter the number of data you want to enter: ";
    int n; cin>>n;
    for(int i=0; i<n; i++)
    {
        int temp; cin>>temp;
        push(&head, temp);
    }
    cout<<"The list you entered is: ";
    printList(head);
    cout<<"Enter the data you want to insert after third position of list: ";
    int x; cin>>x;
    insertAfter(head->next->next,x);
    cout<<"The modified list is: "; printList(head);
    cout<<"Enter the data you want to insert at the end of the list: ";
    int y; cin>>y;
    append(&head, y);
    cout<<"The modified list is: "; printList(head);
    /*removeDuplicates(head);
    cout<<"\nThe list after removing duplicates is: ";
    printList(head);*/
    return 0;
}
