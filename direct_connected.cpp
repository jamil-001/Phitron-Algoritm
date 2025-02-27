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
    int from;
    cin >> from;
    int cnt = 0;
    for(int i = 0;i<n;i++){
        if(i == from){
            for(int x : adj_list[i]){
                cnt++;
            }
        }
        
    }
    cout << cnt << endl;

    return 0;
}