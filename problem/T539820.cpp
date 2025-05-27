#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,e;
	cin>>e>>a>>b>>c>>d;
	if(e==0)cout<<a+b;
	else cout<<max(a-c,0)+max(b-d,0);
	
	return 0;
}
