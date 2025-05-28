#include<bits/stdc++.h>
#define int long long
using namespace std;
int n,a[50004],b[50004],ans;
signed main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
    {
		cin>>a[i];
	}
	for(int i=1;i<=n;i++)
    {
		cin>>b[i];
	}
	sort(a+1,a+1+n);
	sort(b+1,b+1+n);
	for(int i=1,j=1;i<=n;i++)
    {
		if(a[i]>b[j])
        {
			j++,ans++;
		}
	}
	cout<<ans;
	return 0;
}
