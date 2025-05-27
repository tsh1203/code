#include<bits/stdc++.h>
using namespace std;
const long long sb=1000000000;
long long n,m;
int nn=0;
long long sum;
int main()
{
	cin>>n>>m;
	int t=n;
	while(t)
	{
		nn++;
		t/=10;
	}
	nn--;
	if(nn*m>10)
	{
		cout<<-1;
		return 0;
	}
	sum=pow(n,m);
	if(sum>sb)
	{
		cout<<-1;
		return 0;
	}
	cout<<sum;
	return 0;
} 
