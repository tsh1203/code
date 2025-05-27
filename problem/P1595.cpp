#include<bits/stdc++.h>
#define int long long
using namespace std;
int f[100005],n;
signed main()
{
	cin>>n;
    f[0]=1;
	f[1]=0;
	for(int i=2;i<=n;i++)
    {
        f[i]=(i-1)*(f[i-1]+f[i-2]);
    }
	cout<<f[n];
	return 0;
 } 
