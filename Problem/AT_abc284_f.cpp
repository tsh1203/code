#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,t;
string s;
char a[1000006],b[1000006]; 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>s;
	for(int i=0;i<n;i++)
	{
		a[i]=s[i],b[i]=b[i+n]=s[2*n-i-1];
	}
	int x=strstr(b,a)-b;
	if(x<0)
	{
		cout<<-1;
		return 0;
	}
	x=n-x;
	for(int i=0;i<x;i++)cout<<s[i];
	for(int i=n+x;i<2*n;i++)cout<<s[i];
	cout<<endl<<x;
	return 0;
}
