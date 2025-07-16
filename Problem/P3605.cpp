#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,p,cnt,tim;
int head[100005];
int st[100005],en[100005],a[1000005],b[100005];
int k;
int s[100005],ans[1003];
vector<int>v[1003];
struct ed
{
	int v,nxt;
}e[2000006];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	st[u]=++tim;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)
		{
			dfs(v,u);
		}
	}
	en[u]=tim;
}
void init()
{
	k=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		s[i]=(i-1)/k+1;
		v[s[i]].push_back(a[i]); 
	}
	for(int i=1;i<=s[n];i++)
		sort(v[i].begin(),v[i].end());
}
int sum(int l,int r,int c)
{
	int an=0;
	if(l>r)swap(l,r);
	for(int i=s[l]+1;i<s[r];i++){
		an+=lower_bound(v[i].begin(),v[i].end(),c)-v[i].begin();
	}
	for(int i=l;i<=min(r,s[l]*k);i++)
		if(a[i]<c){
			an++;
			//cout<<i<<" "<<a[i]<<endl;
		}
	if(s[l]!=s[r])
		for(int i=r;i>=(s[r]-1)*k+1;i--)
			if(a[i]<c){
				an++;
				//cout<<i<<" "<<a[i]<<endl;
			}
	
	return an;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>b[i];
	for(int i=2;i<=n;i++)
	{
		int x;
		cin>>x;
		add(x,i);
		add(i,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
		a[st[i]]=b[i];
	init();
	for(int i=1;i<=n;i++)
	{
		int l=st[i],r=en[i];
		cout<<r-l+1-sum(l,r,a[st[i]]+1)<<endl;
	}
//	for(int i=1;i<=n;i++)
//	{
//		int l=st[i],r=en[i];
//		int an=0;
//		for(int j=l;j<=r;j++)
//			if(a[j]>a[st[i]])
//			{
//				an++;
//			}
//		cout<<an<<endl;
//	}
	return 0;
}

