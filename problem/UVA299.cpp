#include<bits/stdc++.h>
using namespace std;
int t,n,a[100];
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n;i++)
			cin>>a[i];
		int s=0;
		for(int i=1;i<=n;i++)
			for(int j=i+1;j<=n;j++)
				s+=(a[i]>a[j]);
		cout<<"Optimal train swapping takes "<<s<<" swaps.\n";
	}
	return 0;
}
