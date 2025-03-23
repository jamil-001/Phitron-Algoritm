#include<bits/stdc++.h>
using namespace std;

int n,m;
vector<pair<int,int>> d = {{0,-1},{0,1},{1,0},{-1,0}};
char grid[1004][1004];
bool vis[1005][1005];
bool reach = false;
bool valid(int i,int j){
    if(i < 0 || i >= n || j < 0 || j >= m)
       return false;
    return true;
}
void dfs(int si,int sj,int di,int dj){
    if(si == di && sj == dj){
        reach = true;
        return;
    }
     vis[si][sj] = true;
     for(int i=0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(valid(ci,cj) && !vis[ci][cj] && grid[ci][cj] == '.'){
            dfs(ci,cj,di,dj);
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
    int si,sj,di,dj;
    cin >> si >> sj;
    cin >> di >> dj;
    dfs(si,sj,di,dj);
    if(reach){
        cout << "YES" << endl;
    }else{
        cout <<"NO" << endl;
    }
    return 0;
}