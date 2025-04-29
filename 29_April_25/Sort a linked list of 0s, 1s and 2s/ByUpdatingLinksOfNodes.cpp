#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node *next;

    Node(int val){
        data = val;
        next = nullptr;
    }
};

Node *sortList(Node *head){
    if(!head || !head->next){
        return head;
    }

    Node *zeroD = new Node(0);
    Node *oneD = new Node(0);
    Node *twoD = new Node(0);

    Node *zero = zeroD, *one = oneD, *two = twoD;

    Node *curr = head;
    while(curr != NULL){
        if(curr->data == 0){
            zero->next = curr;
            zero = zero->next;
        }
        else if(curr->data == 1){
            one->next = curr;
            one = one->next;
        }
        else{
            two->next = curr;
            two = two->next;
        }
        curr = curr->next;
    }

    if(oneD->next){
        zero->next = oneD->next;
    }
    else{
        zero->next = twoD->next;
    }

    one->next = twoD->next;
    two->next = nullptr;

    head = zeroD->next;
    return head;
}

void printList(Node *node){
    while(node != nullptr){
        cout<<" "<<node->data;
        node = node->next;
    }
    cout<<endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout<<"Linked List before Sosting:";
    printList(head);

    head = sortList(head);

    cout<<"Linked List after Sorting:";
    printList(head);

    return 0;
}