#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int n,nxt[1000006];
string s;
signed main()
{
	cin>>n>>s;
	s=' '+s;
	for(int i=2,j=0;i<=n;i++)
	{
		while(j&&s[i]!=s[j+1]) j=nxt[j];
		if(s[i]==s[j+1])j++;
		nxt[i]=j;
	}
	cout<<n-nxt[n];
	return 0;
}
