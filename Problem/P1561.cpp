#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
struct no{
    int u;
    int v;
};
bool cmp(no a,no b){
	if(a.u<a.v)
		if(b.u<b.v)return a.u<b.u;
		else return 1;
	else
		if(b.u<b.v)return 0;
		else return a.v>b.v;
}
int n,sum,ans;
no a[30004];
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i].u>>a[i].v;
    sort(a,a+n,cmp);
    for(int i=0;i<n;++i){
        sum+=a[i].u;
        int x=max(ans,sum);
        ans=x+a[i].v;
    }
    cout<<ans<<endl;
    
    return 0;
}
