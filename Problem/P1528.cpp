#include<bits/stdc++.h>
using namespace std;
const int N=2e3+3;
int mid;
int n,m;
int a[N],b[N],cnt[N],tp[N];
int t,s;
bool dfs(int x,int y){
	if(x<=0)return 1;
	if(t-s<cnt[mid])return 0;
	for(int i=y;i<=n;i++){
		if(tp[i]>=b[x]){
			tp[i]-=b[x];
			if(tp[i]<b[1])s+=tp[i];
			if(b[x]==b[x-1]){
				if(dfs(x-1,i))return 1;
			}
			else if(dfs(x-1,1))return 1;
			if(tp[i]<b[1])s-=tp[i];
			tp[i]+=b[x];
		}
	}
	return 0;
}
signed main(){
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		t+=a[i];    
	}
	cin>>m;
	for(int i=1;i<=m;i++){
		cin>>b[i];
	}
	sort(a+1,a+n+1);
	sort(b+1,b+m+1);
	for(int i=1;i<=m;i++)
		cnt[i]=cnt[i-1]+b[i];
	while(cnt[m]>t)m--;
	
	int l=0,r=m;
	while(l<=r){
		mid=(l+r)>>1;    
		for(int i=1;i<=n;i++)
			tp[i]=a[i];
		s=0;
		if(dfs(mid,1))l=mid+1;
		else r=mid-1;        
	}
	cout<<l-1;
	return 0;
}
