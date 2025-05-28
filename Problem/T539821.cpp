#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;
	if(a+b>=d)cout<<"Yes";
	else cout<<"No";
	cout<<endl;
	if(a+c>=d)cout<<"Yes";
	else cout<<"No";
	cout<<endl;
	if(b+c>=d)cout<<"Yes";
	else cout<<"No";
	return 0;
}
