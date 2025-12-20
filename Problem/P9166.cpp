#include<bits/stdc++.h>
#define int long long
#define endl "\n"
#define pii pair<int,int>
#define FAST_IO ios::sync_with_stdio(false),cin.tie(0)
using namespace std;
const int N=2e5+5;
int n,m,x;
pii a[N];
bool ans[N];
bool cmp(pii a,pii b){return a.second>b.second;} 
signed main(){
	FAST_IO;
	cin>>n>>m>>x;
	for(int i=1;i<=m;i++)
		cin>>a[i].first>>a[i].second;
	sort(a+1,a+m+1);
	int mx=x;
	for(int i=1;i<=m&&a[i].first<=mx;i++){
		if(a[i].second>x){
			mx=max(a[i].second,mx);
			ans[a[i].second]=1;
		}
	}
	sort(a+1,a+m+1,cmp);
	mx=x;
	for(int i=1;i<=m&&a[i].second>=mx;i++){
		if(a[i].first<x){
			mx=min(a[i].first,mx);
			ans[a[i].first]=1;
		}
	}
	for(int i=1;i<=n;i++)
		if(ans[i])
			cout<<i<<" ";
	return 0;
}
