#include <bits/stdc++.h>
using namespace std;

int main(){
    vector<int> v;
    int n;
    cin>>n;
    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        v.push_back(x);
        int cur_in = v.size() - 1;
        while(cur_in!=0){
            int parent_in = (cur_in -1)/2;
            if(v[parent_in]>v[cur_in])
            swap(v[parent_in],v[cur_in]);
            else break;
            cur_in = parent_in;
        }
    }
    for(int val:v) cout<<val<<" ";
    return 0;
}