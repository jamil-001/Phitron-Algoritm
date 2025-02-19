#include<bits/stdc++.h>
using namespace std;
int fun(int &a,int &b){
    swap(a,b);
    return a,b;
}
int main(){
    int a= 5,b= 10;
    fun(a,b);
    cout << "a = "<< a <<" b = " << b << endl;

    return 0;
}