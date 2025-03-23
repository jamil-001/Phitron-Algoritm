#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n, m;
bool valid(int i ,int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
       return false;
    return true;
}
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
void bfs(int si,int sj){
     queue<pair<int,int>>q;
     q.push({si,sj});
     vis[si][sj] = true;
     while(!q.empty()){
           pair<int,int> par = q.front();
           q.pop();
           int par_i = par.first;
           int par_j = par.second;
           for(int i=0;i<4;i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj] == '.'){
                q.push({ci,cj});
                vis[ci][cj] = true;
            }
           }
     }
     
}
int main(){
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    int cnt = 0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == false && grid[i][j] == '.'){
                bfs(i,j);
                cnt += 1;
            }
        }
    }
    cout << cnt << endl;
    
    return 0;
}