// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-22-binary-search-treesDay
// Day 22: Binary Search Trees

#include <iostream>

using namespace std;

class Node{
public:
    int data;
    Node *left,*right;
    Node(int d){
        data=d;
        left=right=NULL;
    }
};

class Solution{
public:
    Node* insert(Node* root, int data){
        if(root==NULL){
            return new Node(data);
        }
        else{
            Node* cur=new Node(data);
            if(data<=root->data){
                cur=insert(root->left,data);
                root->left=cur;
            }
            else{
               cur=insert(root->right,data);
               root->right=cur;
             }
       return root;
       }
    }
    int getHeight(Node* root){
        if (!root) return 0;
        return 1 + max(getHeight(root->left), getHeight(root->right));
    }
};//End of Solution

int main(){
    Solution myTree;
    Node* root=NULL;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        root= myTree.insert(root,data);
    }
    int height= myTree.getHeight(root);
    cout<<height;
    return 0;
}
