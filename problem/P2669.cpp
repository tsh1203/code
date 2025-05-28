#include<bits/stdc++.h>
using namespace std;
int k,n,ans;
int main()
{
	cin>>k;
	n=(sqrt(1+8*k)-1)/2;
	ans=n*(n+1)*(2*n+1)/6;
	k-=n*(n+1)/2;
	ans+=k*(n+1);
	cout<<ans;
	return 0;
}
