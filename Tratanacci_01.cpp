#include<bits/stdc++.h>
using namespace std;
int fibo(int n){
    if(n == 0) return 0;
    if(n == 1 || n == 2) return 1;
    if(n == 3) return 2;
    return fibo(n-1)+fibo(n-2)+fibo(n-3)+fibo(n-4);
}
int main(){
    int n;
    cin >> n;
    cout << fibo(n) << endl;
    return 0;
}
//0 1 1 2 