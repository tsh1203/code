#include<bits/stdc++.h>
#define endl "\n"
#define int long long
using namespace std;
long long t,n,k; 
signed main() 
{
	cin>>t;
	while(t--)
	{
		cin>>n;
		k=1;
		if(n==0)
		{
			cout<<"NO!"<<endl;
		}
		else
		{
			while(n%2==0)
			{
				n/=2;
				k++;
			}
			cout<<k<<endl;
		}
	}
	return 0;
}
