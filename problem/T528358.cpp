#include<bits/stdc++.h>
using namespace std;
int main()
{
	int n,sum=INT_MAX;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		b*=7;
		b-=7;
		sum=min(a+b+1,sum);
	}
	cout<<sum;
	return 0;
}
