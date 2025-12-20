#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
using namespace std;
const int N=1e3+3;
int n,m;
int a[N][N];
int f[N][N]; 
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout);
	cin>>n>>m;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			cin>>a[i][j];
	memset(f,128,sizeof f);
	f[1][0]=0;
	for(int i=1;i<=m;i++){
		int an=-1e12;
		for(int j=1;j<=n;j++){
			an=max(an,f[j][i-1])+a[j][i];
			f[j][i]=max(f[j][i],an);
		}
		an=-1e12; 
		for(int j=n;j>0;j--){
			an=max(an,f[j][i-1])+a[j][i];
			f[j][i]=max(f[j][i],an); 
		}
	}
	cout<<f[n][m];
	return 0;
}
