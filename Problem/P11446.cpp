#include<bits/stdc++.h>
#define int long long
using namespace std;
int a[100005];
signed main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		map<int,int>b;
		int c=0;
		cin>>n;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
			if(b[a[i]]==1)c++;
		}
		if(c==n)cout<<n<<endl;
		else if(a[1]==a[n])cout<<1<<endl;
		else if(b[a[1]]>1||b[a[n]]>1)cout<<2<<endl;
		else cout<<3<<endl;
	}
	return 0;
	
}
