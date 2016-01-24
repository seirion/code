// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-23-review-and-binary-trees
// Day 23: Review+Binary Trees!

#include <iostream>

using namespace std;

#include <iostream>
#include <cstddef>
#include <queue>
#include <string>
#include <cstdlib>

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
                Node* cur;
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
    void levelOrder(Node * root){
        if (!root) return;
        queue<Node *> Q;
        Q.push(root);
        while (!Q.empty()) {
            Node *node = Q.front(); Q.pop();
            cout << node->data << " ";
            if (node->left) Q.push(node->left);
            if (node->right) Q.push(node->right);
        }
        cout << endl;
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
    myTree.levelOrder(root);
    return 0;
}
