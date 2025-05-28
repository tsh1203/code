#include<bits/stdc++.h>
using namespace std;
int n,ans,k;
int main()
{
	cin>>n;
	while(n)
	{
		ans++;
		if(k==0&&n%3==1)
			k=ans;
		if(n%3==0)
			n-=n/3;
		else n-=n/3+1;
	}
	cout<<ans<<" "<<k;
	return 0;
}
