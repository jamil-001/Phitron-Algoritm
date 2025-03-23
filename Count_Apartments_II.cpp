#include<bits/stdc++.h>
using namespace std;
char grid[1005][1005];
bool vis[1005][1005];
int n,m;
bool valid(int i,int j){
     if(i < 0 || i >= n || j < 0 || j >= m)
        return false;
    return true;
}
vector<pair<int,int>> d = {{-1,0},{1,0},{0,-1},{0,1}};
int dfs(int si,int sj){
    vis[si][sj] = true;
    int cnt = 1;

    for(int i=0;i<4;i++){
        int ci = si + d[i].first;
        int cj = sj + d[i].second;
        if(!vis[ci][cj] && valid(ci,cj) && grid[ci][cj] =='.'){
            cnt += dfs(ci,cj);   
        }
       
    }
    return cnt;
    
}
int main(){
    
    cin>> n >> m;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin >> grid[i][j];
        }
    }
    memset(vis,false,sizeof(vis));
    vector<int> component;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(vis[i][j] == false && grid[i][j] == '.'){
                int size = dfs(i,j);
                component.push_back(size);
            }
        }
    }
    sort(component.begin(),component.end());
    for(int num : component){
        cout << num <<" ";
    }
    return 0;
}