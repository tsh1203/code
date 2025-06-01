#include<bits/stdc++.h>
using namespace std;
int main(){
    int t,n,m;
    cin>>t;
    while(t--)
    {
        cin>>n>>m;
        if((n+m-1)%4==2)cout<<-1;
        else cout<<1;
    }
    
    return 0;
}
