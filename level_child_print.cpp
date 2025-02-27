#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1004];
bool vis[1005];
int level[1005];
void bfs(int src){
     queue<int> q;
     q.push(src);
     vis[src] = true;
     level[src] = 0;
     while(!q.empty()){
        int par = q.front();
        q.pop();
        for(int child : adj_list[par]){
            if(!vis[child]){
                q.push(child);
                vis[child] = true;
                level[child] = level[par]+1;
            }
        }
     }
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
    memset(level,-1,sizeof(level));
    bfs(0);
    int lvl;
    cin >> lvl;
    vector<int> node_at_level;
    for(int i=0;i<n;i++){
        if(level[i] == lvl){
            node_at_level.push_back(i);
        }
    }
    reverse(node_at_level.begin(),node_at_level.end());
    for(int x : node_at_level){
        cout << x << " ";
    }
    




    return 0;
}