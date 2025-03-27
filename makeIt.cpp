#include<bits/stdc++.h>
using namespace std;
int dp[10005];
bool canarrive(int current,int target){
    if(current > target) return false;
    if(current == target) return true;
    if(dp[current] != -1) return dp[current];
    bool result = canarrive(current + 3,target) || canarrive(current * 2,target);
    dp[current] = result;
    return result;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        memset(dp,-1,sizeof(dp));
        int n;
        cin >> n;
        if(canarrive(1,n)) cout << "YES" << endl;
        else cout <<"NO" <<endl;
    }
    return 0;
}