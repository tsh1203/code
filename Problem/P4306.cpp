#include<bits/stdc++.h>
#define endl "\n"
#define max(a,b) (a>b?a:b)
#define min(a,b) (a<b?a:b)
using namespace std;
const int N=2e3+3;
bitset<N>f[N];
int n,cnt,tot;
char c;
signed main(){
	ios::sync_with_stdio(false);cin.tie(0);
	cin>>n;
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			cin>>c;
			f[i][j]=c-'0';
		}
		f[i][i]=1;
	}
	for(int k=1;k<=n;++k){
		for(int i=1;i<=n;++i){
			if(f[i][k])f[i]|=f[k];
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=n;++j){
			if(f[i][j])++cnt;
		}
	}
	cout<<cnt;
	return 0;
}
