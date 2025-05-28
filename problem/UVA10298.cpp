#include<bits/stdc++.h>
#pragma GCC optimize("3","inline","Ofast")
#define int long long
#define endl "\n"
using namespace std;
int sb[1000006];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	while(1)
	{
		string t;
		cin>>t;
		if(t==".")break;
		int l=t.size();
		int k=-1;
		sb[0]=-1;
		for(int i=1;i<l;i++)
		{
			while(k!=-1&&t[i]!=t[k+1])k=sb[k];
			if(t[i]==t[k+1])k++;
			sb[i]=k;
		}
		int x=l-1;
		if(sb[x]==x)cout<<1<<endl;
		else cout<<(x+1)/(x-sb[x])<<endl;
	}
	return 0;
}
