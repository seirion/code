// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-24-more-review-plus-more-linked-lists
// Day 24: More Review + More Linked Lists!

#include <iostream>

using namespace std;

class Node
{
public:
    int data;
    Node *next;
    Node(int d){
        data=d;
        next=NULL;
    }
};

class Solution{
public:
    Node* removeDuplicates(Node *head)
    {
        Node *node = head;
        while (head) {
            Node *next = head->next;
            if (next && head->data == next->data) {
                head->next = next->next;
                delete next;
            }
            else {
                head = next;
            }
        }
        return node;
    }
    Node* insert(Node *head,int data)
    {
        Node* p=new Node(data);
        if(head==NULL){
            head=p;

        }
        else if(head->next==NULL){
            head->next=p;

        }
        else{
            Node *start=head;
            while(start->next!=NULL){
                start=start->next;
            }
            start->next=p;

        }
        return head;
    }

    void display(Node *head)
    {
        Node *start=head;
        while(start)
        {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
};

int main()
{
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }
    head=mylist.removeDuplicates(head);

    mylist.display(head);
    return 0;
}
