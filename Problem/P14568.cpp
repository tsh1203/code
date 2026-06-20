#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define FIO ios::sync_with_stdio(false);cin.tie(0);
#define memin(a) memset(a,128,sizeof a);
#define memax(a) memset(a,127,sizeof a);
#define memze(a) memset(a,0,sizeof a);
using namespace std;
const int N=5e3+3,mod=998244353;
int n,op[N],f[N][N];
bool chck(){
	for(int i=1;i<=n;i++){
		for(int j=i+1;j<=n;j++){
			if(op[i]==2&&op[j]==0)return 0;
			if(op[i]==3&&op[j]==1)return 0;
		}
	}
	return 1;
}
void print(){
	cerr<<endl;
	for(int i=0;i<=n;i++){
		for(int j=0;j<=n;j++){
			cerr<<setw(5)<<f[i][j]<<" ";
		}
		cerr<<endl;
	}
}
void solve(){
	f[0][0]=1;
	for(int i=1;i<=n;i++){
		if(op[i]<=1){
			for(int j=1;j<=n;j++){
				f[i][j]=f[i-1][j-1];
			}
		}
		else{
//			for(int j=0;j<=n;j++){
//				for(int k=j;k<=n;k++){
//					f[i][j]=(f[i][j]+f[i-1][k])%mod;
//				}
//			}
//			for(int j=0;j<=n;j++){
//				f[i][j]=(f[i][j]+f[i-1][j]*(j+1)%mod)%mod;
//			}
			int cnt=0;
			for(int j=n;j>=0;j--){
				cnt=(cnt+f[i-1][j])%mod;
				f[i][j]=(f[i][j]+cnt)%mod;
			}
			/*
			012345
			12345
			2345
			*/
		}
	}
	int ans=0;
	for(int i=0;i<=n;i++)ans=(ans+f[n][i])%mod;
	cout<<ans;
}
signed main(){
	FIO;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>op[i];
	}
	if(!chck()){
		cout<<0;
		return 0;
	}
	solve();
	return 0;
}
/*
0 比前面都小
1 比前面都大
2 比后面都小
3 比后面都大
*/
