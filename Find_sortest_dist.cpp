#include<bits/stdc++.h>
using namespace std;
vector<int> adj_list[1005];
bool vis[1005];
int level[1005];
void bfs(int src){
    queue<int>q;
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
                level[child]= level[par]+1;
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
    
    int t;
    cin >> t;
    while(t--){
        int src,dst;
        cin >> src >> dst;
        memset(vis,false,sizeof(vis));
        memset(level,-1,sizeof(level));
        bfs(src);
        
        cout << level[dst] << endl;
    }
    
    return 0;
}
/*
6 7
0 1
0 2
1 2
0 3
4 2
3 5
4 3
6
0 5
1 5
2 5
2 3
1 4
0 0

2
3
3
2
2
0
*/