#include<bits/stdc++.h>
using namespace std;
class edge{
    public:
    int a,b,c;
    edge(int a,int b,int c){
        this->a = a;
        this-> b = b;
        this->c = c;
    }
};
int n,e;
int dis[1005];
vector<edge> edge_list;
void bellman_ford(){
     for(int i=0;i<n-1;i++){
        for(auto ed : edge_list){
            int a,b,c;
            a = ed.a;
            b = ed.b;
            c = ed.c;
            if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
                dis[b] = dis[a]+ c;
            }
        }
     }
     bool cycle = false;
     for(auto ed : edge_list){
        int a,b,c;
        a = ed.a;
        b = ed.b;
        c = ed.c;
        if(dis[a] != INT_MAX && dis[a] + c < dis[b]){
            cycle = true;
            break;
        }
     }
     if(cycle)
        cout <<"Negetive weight cycle"<< endl;
    else{
        for(int i =0;i<n;i++){
            cout<< i <<" -> " << dis[i]<<endl;
        }
    }
}
int main(){
    cin >> n >> e;
    while(e--){
        int a,b,c;
        cin >> a >> b >> c;
        edge_list.push_back(edge(a,b,c));
    }
    for(int i=0;i<n;i++){
        dis[i] = INT_MAX;
    }
    dis[0] = 0;
    bellman_ford();
    
    return 0;
}