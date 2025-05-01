#include<bits/stdc++.h>
using namespace std;

vector<int> nthRowOfPascalTriangle(int n){
    n--;
    vector<int>res;
    int prev = 1;
    res.push_back(prev);
    for(int i=1;i<=n;i++){
        int curr = (prev *(n-i+1))/i;
        res.push_back(curr);
        prev = curr;
    }
    return res;
}
int main(){
    int n = 4;
    vector<int> ans = nthRowOfPascalTriangle(n);
    for(int i=0;i<ans.size();i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}