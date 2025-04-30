#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node(int x){
        data = x;
        next = nullptr;
    }
};

int countNodes(Node* node){
    int res = 1;
    Node* curr = node;
    while(curr->next != node){
        res++;
        curr = curr->next;
    }
    return res;
}

int countNodesinLoop(Node* head){
    Node *slow = head;
    Node *fast = head;

    while(slow != nullptr && fast != nullptr){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast){
            return countNodes(slow);
        }

    }
    return 0;

}
int main(){
    Node* head = new Node(1);
    head->next = new Node(2);
    head->next->next  = new Node(3);
    head->next->next->next = new Node(4);
    head->next->next->next->next = new Node(5);

    head->next->next->next->next->next = head->next; // Creating a loop for testing
    cout << "Length of loop is: " << countNodesinLoop(head) << endl; // Output: 4
    return 0;
}