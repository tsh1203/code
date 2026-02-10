#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,now;
int p[1000006],s[1000006],cnt[1000006],ans[1000006];
struct no{
	int x,y,id;
}a[1000006];
bool cmp(no x,no y){
	if(s[x.x]==s[y.x])return x.y<y.y;
	return x.x<y.x;
}
void move(int x,int d){
	if(d){
		if(!cnt[p[x]])now++;
		cnt[p[x]]++;
	}
	else{
		cnt[p[x]]--;
		if(!cnt[p[x]])now--;
	}
}
signed main(){
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>p[i];
	cin>>m;
	int k=sqrt(n);
	for(int i=1;i<=n;i++)
		s[i]=(i-1)/k+1;
	for(int i=1;i<=m;i++){
		cin>>a[i].x>>a[i].y;
		a[i].id=i;
	}
	sort(a+1,a+m+1,cmp);
	int l=0,r=0;
	for(int i=1;i<=m;i++){
		while(l<a[i].x)move(l++,0);
		while(l>a[i].x)move(--l,1);
		while(r<a[i].y)move(++r,1);
		while(r>a[i].y)move(r--,0);
		ans[a[i].id]=now;
	}
	for(int i=1;i<=m;i++)
		cout<<ans[i]<<endl;
	return 0;
}

