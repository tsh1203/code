#include<bits/stdc++.h>
using namespace std;
int ans,n,i,j,a[1010];
int main()
{
	cin>>n;
	ans=0;
	for (i=0;i<n;i++)
		cin>>a[i];
	for (i=0;i<n;i++)
		for (j=i+1;j<n;j++)
			if (a[j]<a[i])
				ans++;
	cout<<ans;
	return 0;
}
