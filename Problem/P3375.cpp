#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,m,nxt[1000006];
string a,b;
signed main()
{
	cin>>a>>b;
	n=a.length();
	m=b.length();
	for(int i=1,j=0;i<m;i++)
	{
		j=nxt[i];
		while(j&&b[i]!=b[j])j=nxt[j];
		if(b[i]==b[j])nxt[i+1]=j+1;
	}
	for(int i=0,j=0;i<n;i++)
	{
		while(j&&a[i]!=b[j])j=nxt[j];
		if(a[i]==b[j])j++;
		if(j==m)
		{
			cout<<i-m+2<<endl;
		}
	}
	for(int i=1;i<=m;i++)cout<<nxt[i]<<" ";
	return 0;
}
