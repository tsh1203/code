#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
using namespace std;
const int N=1e6+6;
int T,n,cnt;
string s;
int f[N][2];
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false),cin.tie(0);
	cin>>T;
	while(T--){
		cin>>n>>s;
		s=' '+s;
		cnt=0;
		f[1][0]=1;
		for(int i=2;i<=n;i++){
			f[i][0]=f[i-1][1]+1;//./.i
			if(s[i]!=s[i-1])f[i][0]=max(f[i][0],f[i-1][0]+1);
			f[i][1]=f[i-2][0]+1;
			if(i>3){
				if(s[i-3]!=s[i-1]||s[i-2]!=s[i])f[i][1]=max(f[i][1],f[i-2][1]);
			}
		}
		cout<<max(f[n][0],f[n][1])<<"\n";
	}
	return 0;
}
//p/pp/q/qp/p/pp/q
//1 
