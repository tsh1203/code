#include<bits/stdc++.h>
#define FIO ios::sync_with_stdio(0);cin.tie(0);
#define int long long
#define pii pair<int,int>
#define endl "\n"
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mem memset
#define gcd __gcd
#define lcm(a,b) ((a*b)/__gcd(a,b))
using namespace std;
const int N=6e4+4,M=50;
int n,c,f[N][M],mx=-1,num[N][M];
struct no{
	int e;
	vector<int>x,y;
}a[N];
int fun(int x,int y){return((x&15)<<1)|y;}
bool chk(int x,int i){
	for(int j:a[i].x)
		if(x&(1<<((j-a[i].e+n)%n)))return 1;
	for(int j:a[i].y)
		if(!(x&(1<<((j-a[i].e+n)%n))))return 1;
	return 0;
}
signed main(){
	FIO
	cin>>n>>c;
	for(int i=1;i<=c;i++){
		int fn,ln,t;
		cin>>a[i].e>>fn>>ln;
		for(int j=1;j<=fn;j++)cin>>t,a[i].x.push_back(t);
		for(int j=1;j<=ln;j++)cin>>t,a[i].y.push_back(t);
		for(int s=0;s<32;s++)if(chk(s,i))num[a[i].e][s]++;
	}
	
	for(int i=0;i<32;i++){
		mem(f,128,sizeof f);
		f[0][i]=0;
		for(int j=1;j<=n;j++)
			for(int k=0;k<32;k++)
				f[j][k]=max(f[j-1][(k&15)<<1],f[j-1][((k&15)<<1)|1])+num[j][k];
		mx=max(mx,f[n][i]);
	}
	cout<<mx;
	return 0;
}
