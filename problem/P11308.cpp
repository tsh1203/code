#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,k,p;
		cin>>n>>m>>k>>p;
		if(k<=m-p/n)
			cout<<"Together\n";
		else if(k<=min(n*m-p,m))
			cout<<"Chance\n";
		else 
			cout<<"Divide\n";
	}	
	return 0;
}
