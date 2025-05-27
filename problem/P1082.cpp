#include<bits/stdc++.h>
#define int long long
using namespace std;
int x,y;
void exgcd(int a,int b)
{
	if(b==0)
	{
		x=1,y=0;
		return;
	}
	exgcd(b,a%b);
	long long t=x;
	x=y;
	y=t-a/b*y;
}
signed main()
{
	int a,b;
	cin>>a>>b;
	exgcd(a,b);
	x=(x%b+b)%b;
	cout<<x;
	return 0;
}
