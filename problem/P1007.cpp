#include<bits/stdc++.h>
using namespace std;
int l,n,a;
int y,x;
int main()
{
	cin>>l>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a<=l/2)
		{
			x=max(a,x);
			y=max(y,l-a+1);
		}
		else
		{
			x=max(l-a+1,x);
			y=max(y,a);
		}
	}
	cout<<x<<" "<<y;
	return 0;
}
