#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d,x;
	cin>>a>>b>>c>>d>>x;
	int ic=(x>=a)?b:0;
	int cc=(x>=c)?d:0;
	int t=ic+cc;
	cout<<t;
	return 0;
}
