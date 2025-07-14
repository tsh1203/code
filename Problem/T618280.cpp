#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int fun(int d)
{
	int an=0;
	if(d<=10)
	{
		an=d*20;
	}
	else if(d<=50)
	{
		an=10*20;
		int t=d-10;
		if(t%5!=0){
			t=(t/5+1)*5;
		}
		an+=(t/5)*80;
	}
	else
	{
		an=10*20+(50-10)*(80/5);
		int t=d-50;
		if(t%10!=0){
			t=(t/10+1)*10;
		}
		an+=(t/10)*120;
	}
	return an;
}
signed main()
{
	int x;
	cin>>x;
	int ans=fun(x);
	for(int i=1;i<x;i++)
	{
		int an=fun(i)+fun(x-i);
		if(an<ans)
		{
			ans=an;
		}
	}
	cout<<ans;
	return 0;
}
