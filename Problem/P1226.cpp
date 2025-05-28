#include <iostream>
using namespace std;
long long fp(long long a, long long b, long long p)
{
	long long res = 1;
	while(b)
	{
		if(b&1)
		{
			res=res*a%p;
		}
		a=a*a%p;
		b>>=1;
	}
	return res;
}
int main()
{
	long long a, b, p;
	cin>>a>>b>>p;
	long long s=fp(a, b, p);
	cout<<a<<"^"<<b<<" mod "<<p<<"="<<s<<endl;
	return 0;
}    
