#include<bits/stdc++.h>
using namespace std;
long long t, n, d, k; 
int main()
{
	cin >> t; 
	while (t--)
	{
		cin>>n>>d>>k; 
		k--;
		cout<<(k*d+k/(n/__gcd(n, d)))%n<<"\n";
	}
	return 0;
}
