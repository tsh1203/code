#include<bits/stdc++.h>
#define int long long
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
#define endl "\n"
using namespace std;
const int N=1e3+5,M=205,mod=1e9+7;
int n,m,k;
int f[4][M][M][2];
string a,b;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n>>m>>k;
	cin>>a>>b;
	a=" "+a,b=" "+b;
//	for(int i=1;i<=n;i++)f[i&1][0][0][0]=1;
	f[1][0][0][0]=f[0][0][0][0]=1;
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			for(int kk=1;kk<=min(j,k);kk++){
				f[i&1][j][kk][0]=(f[(i-1)&1][j][kk][0]+f[(i-1)&1][j][kk][1])%mod;
				if(a[i]==b[j])
					f[i&1][j][kk][1]=(f[(i-1)&1][j-1][kk-1][0]+f[(i-1)&1][j-1][kk][1]+f[(i-1)&1][j-1][kk-1][1])%mod;
				else f[i&1][j][kk][1]=0;
//				cout<<"{"<<f[i&1][j][kk][0]<<","<<f[i&1][j][kk][1]<<"}";
			}
		}
//		cout<<endl;
	}
	cout<<(f[n&1][m][k][1]+f[n&1][m][k][0])%mod;
	return 0;
}
