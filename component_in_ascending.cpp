#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int dfs(int src){
    //cout << src << " ";
    vis[src] = true;
    int cnt = 1;
    for(auto child : adj_list[src]){
        if(!vis[child]){
            cnt += dfs(child);
            
        }
       
    }
    return cnt;
    
}
int main(){
    int n,e;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
        adj_list[b].push_back(a);
    }
    
    memset(vis,false,sizeof(vis));
    vector<int> component;

    for(int i=0;i<n;i++){
        if(vis[i] == false){
            int size = dfs(i);
            component.push_back(size);
        }
    }
    sort(component.begin(),component.end());
    for(int size : component){
        cout << size <<" ";
    }
    return 0;
}