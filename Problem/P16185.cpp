#include<bits/stdc++.h>
#define FIO ios::sync_with_stdio(false);cin.tie(0);
#define int long long
#define pii pair<int,int>
#define endl "\n"
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define mem memset
#define gcd __gcd
#define lcm(a,b) ((a*b)/__gcd(a,b))
using namespace std;
const int N=5e6+6;
int n,a[N],lc=2520,mx;
int lst[20],f[N];
signed main(){
	FIO
	cin>>n;
	mem(f,127,sizeof f);
	f[1]=0;
	for(int i=1;i<=n;i++)cin>>a[i],mx=max(mx,a[i]);
	for(int i=1;i<=n;i++){
		for(int j=max(1,i-9);j<i;j++)if(a[j]>=i-j)f[i]=min(f[i],f[j]+(i-j)*(lc/a[j]));
		if(lst[a[i]]!=0)f[i]=min(f[i],f[lst[a[i]]]+lc);
		lst[a[i]]=i;
	}
//	for(int i=1;i<=n;i++)cout<<f[i]<<" ";cout<<endl;
	int gc=gcd(f[n],lc);
	cout<<f[n]/gc<<" "<<lc/gc;
	return 0;
}
