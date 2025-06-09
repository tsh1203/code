#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,a[5003],f[5003];
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		a[i]+=a[i-1];
	}
	
	memset(f,128,sizeof(f));
	f[0]=0;
	
	for(int i=1;i<=n;i++)
		for(int j=0;j<i;j++)
			f[i]=max(f[i],f[j]+a[(i-j)/2]+a[(i-j-1)/2]);
	cout<<f[n];
	return 0;
}
