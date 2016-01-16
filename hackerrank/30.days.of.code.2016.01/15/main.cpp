// hackerrank 30 Days of Code
// https://www.hackerrank.com/contests/30-days-of-code/challenges/day-15-linked-list
// Day 15: Linked List!
#include <iostream>
#include <cstddef>

using namespace std;    
class Node {
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
    Node* insert(Node *head,int data) {
        if (head == NULL) {
            head = new Node(data);
        }
        else {
            Node *now = head;
            while (true) {
                if (now->next == NULL) {
                    now->next = new Node(data);
                    break;
                }
                now = now->next;
            }
            now = new Node(data);
        }
        return head;
    }

    void display(Node *head) {
        Node *start=head;
        while(start) {
            cout<<start->data<<" ";
            start=start->next;
        }
    }
};

int main() {
    Node* head=NULL;
    Solution mylist;
    int T,data;
    cin>>T;
    while(T-->0){
        cin>>data;
        head=mylist.insert(head,data);
    }   
    mylist.display(head);
    return 0;
}
