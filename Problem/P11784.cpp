#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a;
		if(a[0]>='0'&&a[0]<='9')b="https://www.luogu.com.cn/problem/P"+a;
		else b="https://www.luogu.com.cn/problem/"+a;
		cout<<b<<endl;
	}
	return 0;
}
