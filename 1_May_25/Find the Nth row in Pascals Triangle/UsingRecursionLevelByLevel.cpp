#include<bits/stdc++.h>
using namespace std;

vector<int> nthRowOfPascalTriangle(int n){
    vector<int> curr;
    curr.push_back(1);

    if(n==1){
        return curr;
    }

    vector<int> prev = nthRowOfPascalTriangle(n-1);
    for(int i=1;i<prev.size();i++){
        int val = prev[i-1]+prev[i];
        curr.push_back(val);
    }
    curr.push_back(1);
    return curr;
}

int main(){
    int n=4;
    vector<int> ans = nthRowOfPascalTriangle(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}