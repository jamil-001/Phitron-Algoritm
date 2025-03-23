#include<bits/stdc++.h>
using namespace std;
vector<int>adj_list[100005];
bool bfs(int src,int dst){
        for(auto child : adj_list[src]){
            if(child == dst || src == dst) return true;
        }
        return false;
}
int main(){
    int n,e,q;
    cin >> n >> e;
    while(e--){
        int a,b;
        cin >> a >> b;
        adj_list[a].push_back(b);
    }
    
    cin >> q;
    while(q--){
        int src,dst;
        cin >> src >> dst;
        
        if(bfs(src,dst)){
            cout << "YES" << endl;
        }else{
            cout <<"NO" << endl;
        }
    }
    return 0;
}