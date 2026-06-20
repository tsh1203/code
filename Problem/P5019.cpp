#include<bits/stdc++.h>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define endl "\n"
using namespace std;
const int N=1e5+5;
int n;
int a[N],f[N];
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++){
		if(a[i]<=a[i-1])f[i]=f[i-1];
		else f[i]=f[i-1]+(a[i]-a[i-1]);
	}
	cout<<f[n];
	return 0;
}
