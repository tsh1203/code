#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define mem(a) memset((a),0,sizeof((a)))
#define memin(a) memset((a),128,sizeof((a)))
#define memax(a) memset((a),127,sizeof((a)))
using namespace std;
const int N=1e4+4,M=502;
int n,m;
int f[N][M],d[N];
void upd(int &x,int y){
	x=max(x,y);
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	for(int i=1;i<=n;i++)cin>>d[i];
	memin(f),f[0][0]=0;
	for(int i=1;i<=n;i++){
		for(int j=0;j<=min(i,m);j++){
			if(j==0)upd(f[i][j],f[i-1][j]);
			if(j)upd(f[i][j],f[i-1][j-1]+d[i]);
			if(j&&i+j<=n)upd(f[i+j][0],f[i][j]);
		}
	}
	cout<<f[n][0];
	return 0;
}
