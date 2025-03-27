#include<bits/stdc++.h>
using namespace std;
int dp[1005][1005];
int val[1005],weight[1005];
int knapsack(int i,int mx_weight){
    if(i < 0 || mx_weight <= 0) return 0;
    if(dp[i][mx_weight] != -1) return dp[i][mx_weight];
    if(weight[i] <= mx_weight){
        int op1 = knapsack(i-1,mx_weight - weight[i]) + val[i];
        int op2 = knapsack(i-1,mx_weight);
        return dp[i][mx_weight] = max(op1,op2);
    }else{
        return dp[i][mx_weight] = knapsack(i-1,mx_weight);
    }
}
int main(){
    int t;
    cin >> t;
    while(t--){
        int n,mx_weight;
        cin >> n >> mx_weight;
        for(int i=0;i<n;i++) cin >> weight[i];
        for(int i=0;i<n;i++) cin >> val[i];
        memset(dp,-1,sizeof(dp));
        cout << knapsack(n-1,mx_weight) << endl;
    }
    return 0;
}