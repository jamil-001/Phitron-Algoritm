#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[100005];

int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    int q;
    cin >> q;
    while(q--){
            int x;
            cin >> x;
            if(adj_list[x].empty()){
                cout << "-1" << endl;
            }else{
                vector<int>nm;
                for(auto child : adj_list[x]){
                    nm.push_back(child);
                }
                sort(nm.begin(),nm.end());
                reverse(nm.begin(),nm.end());
                for(auto  num : nm){
                    cout << num <<" ";
                }
           cout << endl;

            }      
    } 
    return 0;
}