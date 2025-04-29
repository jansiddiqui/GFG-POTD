#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int val){
        data = val;
        next = NULL;
    }
};

void sortList(Node *head){
    int cnt[3] = {0,0,0};
    Node *ptr = head;

    while(ptr != NULL){
        cnt[ptr->data]++;
        ptr = ptr->next;
    }

    int idx = 0;
    ptr = head;

    while(ptr != NULL){
        if(cnt[idx] == 0){
            idx++;
        }
        else{
            ptr->data = idx;
            cnt[idx]--;
            ptr = ptr->next;
        }
    }
}

void printList(Node *head){
    while(head != NULL){
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

int main(){
    Node *head = new Node(1);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(1);
    head->next->next->next->next = new Node(0);

    cout << "Original List: ";
    printList(head);

    sortList(head);

    cout << "Sorted List: ";
    printList(head);

    return 0;
}