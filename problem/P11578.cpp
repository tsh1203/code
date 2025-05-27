#include<bits/stdc++.h>
using namespace std;
int t,x,y;
int a1=INT_MAX,a2=INT_MAX,b1=INT_MIN,b2=INT_MIN;
int main()
{
	cin>>t;
	while(t--)
	{
		scanf("%d,%d",&x,&y);
		a1=min(a1,x);
		a2=min(a2,y);
		b1=max(b1,x);
		b2=max(b2,y);
	}
	cout<<a1-1<<","<<a2-1<<endl<<b1+1<<","<<b2+1;
	return 0;
}
