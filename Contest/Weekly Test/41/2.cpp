#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n;
vector<int>a;
int dfs(int p,vector<int>a)
{
	if(p<0||a.size()==0)return 0;
    int mask=1<<p;
    vector<int>x,y;
    for(int t:a)
    {
    	if(t&mask)x.push_back(t);
		else y.push_back(t); 
    }
    if(x.size()==0||y.size()==0)
    {
    	return dfs(p-1,a);
    }
    else
    {
    	return mask+min(dfs(p-1,x),dfs(p-1,y));
    }
}

signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int x;
		cin>>x;
		a.push_back(x); 
	}
	cout<<dfs(30,a);
	return 0;
}
