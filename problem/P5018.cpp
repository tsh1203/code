#include<bits/stdc++.h>
using namespace std;
int n;
int a[1000010],s[1000010][2],l[1000010];
void count(int p)
{
	l[p]=1;
	if(s[p][0]!=-1)
	{
		count(s[p][0]);
		l[p]+=l[s[p][0]];
	}
	if(s[p][1]!=-1)
	{
		count(s[p][1]);
		l[p]+=l[s[p][1]];
	}
}
bool check(int p,int v)
{
	if(p==-1&&v==-1)
		return true;
	if(p!=-1&&v!=-1&&a[p]==a[v]&&check(s[p][0],s[v][1])&&check(s[p][1],s[v][0]))
		return true;
	return false;
}
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
		cin>>a[i];
	for(int i=1;i<=n;i++)
		cin>>s[i][0]>>s[i][1];
	count(1);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		if(check(s[i][0],s[i][1]))
			ans=max(l[i],ans);
	}
	cout<<ans;
	return 0;
}
