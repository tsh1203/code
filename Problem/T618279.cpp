#include<bits/stdc++.h>
#define endl "\n"
using namespace std;
int a1,a2,a3,b1,b2,b3,c;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>a1>>b1>>a2>>b2>>a3>>b3>>c;
	int ma=max(b1,max(b2,b3));
	int s1=a1-(ma-b1)*c,s2=a2-(ma-b2)*c,s3=a3-(ma-b3)*c;
	if(s1<=s2&&s1<=s3)
		cout<<1<<" "<<s1;
	else if(s2<=s1&&s2<=s3)
		cout<<2<<" "<<s2;
	else
		cout<<3<<" "<<s3;
	return 0;
}
