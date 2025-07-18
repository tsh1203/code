#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e3+3;
int t,n;
int a[N],f[N][N][2];
int solve(){
	memset(f,0,sizeof f);
	for(int i=1;i<=n;i++)
		f[i][i][0]=f[i][i][1]=a[i];
	for(int len=2;len<=n;len++){
		for(int l=1;l+len-1<=n;l++){
			int r=l+len-1;
			f[l][r][0]=INT_MIN;
			for(int k=l;k<r;k++)
				f[l][r][0]=max(f[l][r][0],min(f[l][k][1],f[k+1][r][1]));
			f[l][r][1]=INT_MAX;
			for(int k=l;k<r;k++)
				f[l][r][1]=min(f[l][r][1],max(f[l][k][0],f[k+1][r][0]));
		}
	}
	return f[1][n][0];
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		cout<<solve()<<endl;
	}
	return 0;
}
