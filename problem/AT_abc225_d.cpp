#include<bits/stdc++.h>
#pragma GCC optimize("3") 
#define endl "\n"
#define int long long
using namespace std;
struct no
{
	int x,y;
};
int a[200005];//后 
int b[200005];//前 
int n; 
int find_front(int x)
{
	if(b[x]==0)return x;
	return find_front(b[x]);
}
int find_back(int x)
{
	if(a[x]==0)return x;
	return find_back(a[x]);
}
int count(int x)
{
	if(b[x]==0)return 1;
	return count(b[x])+1;
}
void out(int x)
{
	cout<<x<<" ";
	if(a[x]!=0)
		out(a[x]);
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>n;
	for(int i=1;i<=n;i++)
	{
		int x,y,z;
		cin>>x;
		if(x==1)
		{
			cin>>y>>z;
			a[y]=z;
			b[z]=y; 
		}
		if(x==2)
		{
			cin>>y>>z;
			a[y]=0;
			b[z]=0;
		}
		if(x==3)
		{
			cin>>y;
			int back=find_back(y);
			cout<<count(back)<<" ";
			out(find_front(y));
			cout<<endl;
		} 
	}
	return 0;
}
