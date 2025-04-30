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

int cntNodesinLoop(Node* head){
    unordered_set<Node*> visited;
    Node* curr = head;
    int cnt = 0;

    while(curr != nullptr){
        if(visited.find(curr) !=  visited.end()){
            struct Node* startOfLoop = curr;
            do{
                cnt++;
                curr = curr->next;
            }while(curr != startOfLoop);
            return cnt;
        }
        visited.insert(curr);
        curr = curr->next;
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
    cout << "Length of loop is: " << cntNodesinLoop(head) << endl; // Output: 4
    return 0;
}