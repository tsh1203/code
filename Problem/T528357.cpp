#include<bits/stdc++.h>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a>>b>>c;
	int x=b-c,y=b+c;
	if(x>=0)cout<<x<<" ";
	if(y<=a&&y!=x)cout<<y;
	if(x<0&&y>a)cout<<"No solution";
	return 0;
}
