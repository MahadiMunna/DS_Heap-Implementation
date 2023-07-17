#include <bits/stdc++.h>
using namespace std;
void insert_at_heap(vector<int> &v,int x){
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
void delete_from_heap(vector<int> &v){
    v[0]=v[v.size()-1];
    v.pop_back();
    int cur = 0;
    while(true){
        int left_in = cur*2+1;
        int right_in = cur*2+2;
        int last_in = v.size()-1;
        if(left_in<=last_in && right_in<=last_in){
            if(v[left_in]<=v[right_in] && v[left_in]<v[cur]){
                swap(v[left_in],v[cur]);
                cur=left_in;
            }
            if(v[right_in]<=v[left_in] && v[right_in]<v[cur]){
                swap(v[right_in],v[cur]);
                cur=right_in;
            }
            else break;
        }
        else if(left_in<=last_in){
            if(v[left_in]<v[cur]){
                swap(v[left_in],v[cur]);
                cur=left_in;
            }
            else break;
        }
        else if(right_in<=last_in){
            if(v[right_in]<v[cur]){
                swap(v[right_in],v[cur]);
                cur=right_in;
            }
            else break;
        }
        else break;
    }
}
int main(){
    int n;cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++){
        int x;cin>>x;
        insert_at_heap(v,x);
    }
    for(int val:v)cout<<val<<" ";
    cout<<endl; 
    delete_from_heap(v);
    for(int val:v)cout<<val<<" ";
    return 0;
}