#include<bits/stdc++.h>
using namespace std;
int a[100][100];
string s;
int n;
int sum=52;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>s;
		int x,y;
		if(s[0]=='D')x=1;
		if(s[0]=='S')x=2;
		if(s[0]=='C')x=3;
		if(s[0]=='H')x=4;
		if(s[1]=='A')y=1;
		else if(s[1]=='T')y=10;
		else if(s[1]=='J')y=11;
		else if(s[1]=='Q')y=12;
		else if(s[1]=='K')y=13;
		else y=s[1]-'0';
		if(a[x][y]==0)
		{
			sum--;
		}
		a[x][y]=1;
	}
	cout<<sum;
	return 0;
}
