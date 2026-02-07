#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define memset mem
using namespace std;
const int N=1e5+5;
int n,s,t,cnt;
long double a[N],b[N],que[N];
bool chck(long double x){
	deque<int>q;
	q.clear();
	for(int i=1;i<=n;i++)
		b[i]=a[i]+b[i-1]-x;
	for(int i=1;i<=n;i++){
		if(i>=s){
			while(q.size()&&b[q.back()]>b[i-s])q.pop_back();
			q.push_back(i-s);
		}
		if(q.size()&&q.front()<i-t)q.pop_front();
		if(q.size()&&b[i]>b[q.front()])return 1;
	}
	return 0;
}
void solve(){
	long double L=-10004,R=10004,ans;
	while(R-L>2e-6){
		long double mid=(L+R)/2.0;
//		cout<<L<<" "<<R<<" "<<mid<<endl;
		if(chck(mid))ans=mid,L=mid;
		else R=mid;
	}
	if(abs(ans-0.0)<0.0005)cout<<"0.000";
	else cout<<fixed<<setprecision(3)<<ans;
}
signed main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s>>t;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	solve();
	return 0;
}
