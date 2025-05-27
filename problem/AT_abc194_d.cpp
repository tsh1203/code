#include<bits/stdc++.h>
using namespace std;
double n,ans;
int main()
{
	cin>>n;
	for(double i=1;i<=n-1;i++)ans+=(n/i);
	cout<<fixed<<setprecision(11)<<ans;
	return 0;
}
