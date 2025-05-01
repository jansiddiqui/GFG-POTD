#include<bits/stdc++.h>
using namespace std;

int findVal(int i, int n){
    if(i==1 || i==n){
        return 1;
    }

    return findVal(i-1, n-1) + findVal(i, n-1);
}
vector<int> nthRowOfPascalTriangle(int n){
    vector<int> res;

    for(int i=1;i<=n;i++){
        int val = findVal(i, n);
        res.push_back(val);
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