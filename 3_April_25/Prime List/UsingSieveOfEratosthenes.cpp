#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
    int val;
    Node* next;

    Node(int num){
        val = num;
        next = NULL;
    }
};

vector<int> findPrimes(int n){
    vector<int> primes(n+1, 1);
    primes[0] = 0;
    primes[1] = 0;
    for(int i=2; i*i<=n; i++){
        if(primes[i]){
            for(int j=i*i;j<=n;j+=i){
                primes[j] = 0;
            }
        }
    }
    return primes;
}
Node* primeList(Node* head){
    int max_num = 0;
    Node* temp = head;
    while(temp != NULL){
        max_num = max(max_num, temp->val);
        temp = temp->next;
    }
    vector<int> primes = findPrimes(2*max_num);

    temp = head;
    while(temp != NULL){
        int num = temp->val;

        if(num == 1){
            temp->val = 2;
        }
        else{
            int num1 = num, num2 = num;
            while(!primes[num1]){
                num1--;
            }
            while(!primes[num2]){
                num2++;
            }
            if(num - num1 > num2 - num){
                temp->val = num2;
            }
            else{
                temp->val = num1;
            }
        }
        temp = temp->next;
    }
    return head;
}

int main(){
    Node* head = new Node(2);
    head->next = new Node(6);
    head->next->next = new Node(10);
    Node* ans = primeList(head);
    while(ans != NULL){
        cout<<ans->val<<" ";
        ans = ans->next;
    }
    cout<<endl;
    return 0;
}