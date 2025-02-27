#include<bits/stdc++.h>
using namespace std;
char grid[105][105];
bool vis[105][105];
int level[105][105];
int n,m;
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
bool valid(int i,int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
       return false;
    return true;
}

void bfs(int si,int sj){
    queue<pair<int,int>> q;
    q.push({si,sj});
    vis[si][sj] = true;
    level[si][sj]=0;
    while(!q.empty()){
        pair<int,int> par = q.front();
        q.pop();
        int par_i = par.first;
        int par_j = par.second;

       // cout << par_i <<" "<< par_j << endl;
        for(int i =0;i<4;i++){
            int ci = par_i + d[i].first;
            int cj = par_j + d[i].second;
            if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj] == '.'){//ignore # 
                q.push({ci,cj});
                vis[ci][cj] = true;
                level[ci][cj] = level[par_i][par_j] + 1;
            }
        }
    }
}
int main(){
    
    cin >> n >> m;
    for(int i=0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    memset(level,-1,sizeof(level));
    int si,sj;
    cin >> si >> sj;
    bfs(si,sj);
    cout << level[1][0] << endl;
    return 0;
}