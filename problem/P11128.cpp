#include<bits/stdc++.h>
using namespace std;
int n,m;
int a[10000];
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		for(int j=1;j<i;j++)
		{
			if(abs(a[i]-a[j])==m)
			{
				cout<<"Yes";
				return 0;
			}
		}
	}
	cout<<"No";
	return 0;
}
