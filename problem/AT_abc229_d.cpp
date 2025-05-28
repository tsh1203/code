#include<bits/stdc++.h>
#pragma GCC optimize("3","inline","Ofast")
#define int unsigned long long
#define endl "\n"
using namespace std;
string s;
int a[200005],n;
int l,r;
int mid;
bool ch()
{
	for(int i=mid-1;i<s.size();i++)
		if(a[i+1]-a[i-mid+1]<=n)return 1;//存在合适位置
	return 0;//不存在合适位置
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>s>>n;
	l=1,r=s.size();
	for(int i=0;i<s.size();i++)
	{
		if(s[i]!='X')a[i+1]++;
		a[i+1]+=a[i];//间隔长度前缀和
	}
	while(l<=r)
	{
		mid=(l+r)/2;
		if(ch())l=mid+1;
		else r=mid-1;
	}
	l--;//rp++,希望减一大法能成
	cout<<l;
	return 0;
}
//orz rp+=INF
