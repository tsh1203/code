#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,q;
int a[1000006],ans[1003],ad[1003];
int s[1000006],k;
vector<int>v[1003];
bool cmp(int x,int y)
{
	return a[x]+ad[s[x]]>a[y]+ad[s[y]]; 
}
int find(int l,int r,int c)
{
	if(l>r)return 0;
	int mid=(l+r)/2;
}
void add(int l,int r,int x)
{
	if(l>r)swap(l,r);
	for(int i=s[l]+1;i<s[r];i++)
	{
		ad[i]+=x;
	}
	for(int i=l;i<=min(r,s[l]*k);i++)
	{
		a[i]+=x;
	}
	if(s[l]!=s[r])
	{
		for(int i=r;i>=(s[r]-1)*k+1;i--)
		{
			a[i]+=x;
		}
	}
	v[s[l]].clear();
	for(int i=(s[l]-1)*k+1;i<=min(s[l]*k,n);i++)
	{
		v[s[l]].push_back(a[i]); 
	}
	sort(v[s[l]].begin(),v[s[l]].end());
	
	v[s[r]].clear();
	for(int i=(s[r]-1)*k+1;i<=min(s[r]*k,n);i++)
	{
		v[s[r]].push_back(a[i]); 
	}
	sort(v[s[r]].begin(),v[s[r]].end());
}
int cnt(int l,int r,int c)
{
	int an=0;
	if(l>r)swap(l,r);
	for(int i=s[l]+1;i<s[r];i++)
	{
		int x=c-ad[i];
		an+=lower_bound(v[i].begin(),v[i].end(),x)-v[i].begin();
	}
	for(int i=l;i<=min(r,s[l]*k);i++)
		if(a[i]+ad[s[i]]<c)
			an++;
	if(s[l]!=s[r])
		for(int i=r;i>=(s[r]-1)*k+1;i--)
			if(a[i]+ad[s[i]]<c)
				an++;
	return an;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>q;
	k=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		s[i]=(i-1)/k+1;
		v[s[i]].push_back(a[i]); 
	}
	for(int i=1;i<=s[n ];i++)
		sort(v[i].begin(),v[i].end());
//	for(int i=1;i<=n;i++)
//	{
//		cout<<a[i]<<" ";
//	}
	while(q--)
	{
		char op;
		int l,r,x;
		cin>>op>>l>>r>>x;
		if(op=='M')add(l,r,x);
		else cout<<r-l+1-cnt(l,r,x)<<endl;
	}
	return 0;
}
