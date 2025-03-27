#include<bits/stdc++.h>
using namespace std;
bool ispile(string a,string b){
    if(a.length() != b.length()) return false;
    sort(a.begin(),a.end());
    sort(b.begin(),b.end());
    return a == b;
}
int main(){
    int t;
    cin >> t;
    while(t--){
        string a,b;
        cin >> a >> b;
        if(ispile(a,b))
          cout << "YES" << endl;
        else 
           cout <<"NO" << endl;
    }
    return 0;
}