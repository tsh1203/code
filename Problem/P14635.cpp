#include<bits/stdc++.h>
//#pragma GCC optimize("3","inline") 
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
int n,m,mm;
int x[N],y[N];
int id,mx=1e18;
int ans1,ans;
bool cmp(int x,int y){
	return x<y;
}
signed main(){
//	freopen(".in","r",stdin); 
//	freopen(".out","w",stdout); 
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>m;
	mm=m;
	x[0]=1e12;
	for(int i=1;i<=n;i++){
		cin>>x[i]>>y[i];
		if(mx>x[i]+y[i]||(x[i]+y[i]==mx&&x[id]>x[i])){
			mx=x[i]+y[i];
			id=i;
		}
	}
	sort(x+1,x+n+1,cmp);
	int cnt=0;
	ans=mm/mx*2;
	if(mm-mx*ans/2>=x[id])ans++;
	for(int i=1;i<=n&&mm>0;i++){
		if(i==id)continue;
		cnt++;
		mm-=x[i];
		int tmp=cnt+mm/mx*2;
		if(mm-mx*ans/2>=x[id])tmp++;
		ans=max(tmp,ans);
	}
	cout<<ans;
	return 0;
}
