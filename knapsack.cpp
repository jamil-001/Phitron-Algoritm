#include<bits/stdc++.h>
using namespace std;
int val[1005],weight[1005];
int knapsack(int i,int mx_weight){
    //option 2
    if(i < 0 || mx_weight <= 0)
    return 0;
    if(weight[i] <= mx_weight){
        int op1 = knapsack(i-1,mx_weight - weight[i]) + val[i] ;
        int op2 = knapsack(i-1,mx_weight);
        return max(op1,op2);
    }else{
        return knapsack(i-1,mx_weight);
    }
    
}
int main(){
    int n,mx_weight;
    cin >> n;
   
    for(int i=0;i<n;i++)
       cin >> val[i];
    for(int i=0;i<n;i++)
        cin >> weight[i];
    cin >> mx_weight;
    cout << knapsack(n-1,mx_weight) << endl;
    return 0;
}