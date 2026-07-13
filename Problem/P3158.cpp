#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FIO ios::sync_with_stdio(false);cin.tie(0);
using namespace std;
const int N=40,mod=1e9+9;
int n,m,c,a[N],b[N];
int C[1000][1000],ans;
int f[N][N][N],g[N][N][N];
signed main(){
	FIO;
	C[1][1]=1;
	for(int i=0;i<=950;i++){
		C[i][0]=1;
		for(int j=1;j<=i;j++){
			C[i][j]=(C[i-1][j]+C[i-1][j-1])%mod;
		}
	}
	cin>>n>>m>>c;
	for(int i=1;i<=c;i++)cin>>a[i];
	for(int T=1;T<=c;T++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				g[T][i][j]=C[i*j][a[T]];
				for(int x=1;x<=i;x++){
					for(int y=1;y<=j;y++){
						if(x!=i||y!=j){
							g[T][i][j]=(g[T][i][j]-g[T][x][y]*C[i][x]*C[j][y]%mod+mod)%mod;
						}
					}
				}
			}
		}	
	}
	f[0][0][0]=1;
	for(int T=1;T<=c;T++){
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i*j<a[T])continue;
				for(int x=1;x<=i;x++){
					for(int y=1;y<=j;y++){
						f[T][i][j]=(f[T][i][j]+(f[T-1][i-x][j-y]*g[T][x][y]%mod)*C[n-(i-x)][x]%mod*C[m-(j-y)][y])%mod;
					}
				}
			}
		}	
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			ans+=f[c][i][j];
			ans%=mod;
		}
	}
	cout<<ans;
	return 0;
}
