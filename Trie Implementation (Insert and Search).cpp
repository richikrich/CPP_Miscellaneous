#include<iostream>
#include<vector>
#include<cmath>
#include<bits/stdc++.h>

using namespace std;

//trie implementation!!!!

const int ALPHABET_SIZE=26;

struct TrieNode
{
    TrieNode* character[ALPHABET_SIZE];
    // isEndOfWord is true if the node represents
    // end of a word
    bool isEndofWord;
};
//Function to return new node, initialized to nulls
TrieNode* getNode()
{
    TrieNode* pNode=new TrieNode;
    pNode->isEndofWord=false;
    for(int i=0; i<ALPHABET_SIZE; i++) pNode->character[i]=nullptr;
    return pNode;
}

void insertNode(TrieNode* root, string key)
{
    TrieNode* pCrawl=root;
    int index;
    for(int i=0; i<key.size(); i++)
    {
        index=key[i]-'a'; //return corresponding index for character in array, i.e., a=0, b=1, c=3, etc.
        if(!pCrawl->character[index]) //if no node exist there, create a node and then move to it
            pCrawl->character[index]=getNode();
        pCrawl=pCrawl->character[index];
    }
    pCrawl->isEndofWord=true; //since it reaches end of word at the end of the loop
}

bool searchNode(TrieNode* root, string key)
{
    TrieNode* pCrawl=root;
    int index;
    for(int i=0; i<key.size(); i++)
    {
        index=key[i]-'a';
        if(!pCrawl->character[index]) return false; //sine that key doesn't exist, clearly
        else pCrawl=pCrawl->character[index];
    }
    if(!pCrawl) return false;
    else
    {
        if(pCrawl->isEndofWord) return true;
    }
}

int main()
{
    TrieNode* root=getNode();
    int n;
    cout<<"Enter no. of keys you wanna insert: ";
    cin>>n;
    vector<string> keys; string temp;
    cout<<"Input: ";
    for(int i=0; i<n; i++)
    {
        cin>>temp;
        keys.push_back(temp);
    }
    cout<<"The keys you entered are: ";
    for(int i=0; i<keys.size(); i++) cout<<keys[i]<<" " ;
    cout<<endl;
    for(int i=0; i<keys.size(); i++) insertNode(root, keys[i]);
    cout<<"Enter number of keys you wanna search: "; cin>>n;
    for(int i=0; i<n; i++)
    {
        cout<<"Key to search: ";
        cin>>temp;
        if(searchNode(root,temp)) cout<<"Found"<<endl;
        else cout<<"Not found :( "<<endl;
    }
    return 0;
}
