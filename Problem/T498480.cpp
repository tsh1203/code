#include<bits/stdc++.h>
using namespace std;
int main()
{
	string s;
	vector<int> a,b;
	cin>>s;
	for(int i=s.size()-1;i>=0;i--) a.push_back(s[i]-'0');
	cin>>s;
	for(int i=s.size()-1;i>=0;i--) b.push_back(s[i]-'0');
	vector<int> c(a.size()+b.size()+10,0);
	for(int i=0;i<a.size();i++)
	{
		for(int j=0;j<b.size();j++)
			c[i+j]+=a[i]*b[j];
	}
	int sum=0;
	for(int i=0;i<c.size();i++)
	{
		sum+=c[i];
		c[i]=sum%10;
		sum/=10;
	}
	int n=c.size()-1;
	while(c[n]==0)n--;
	for(int i=n;i>=0;i--) cout<<c[i];
	return 0;
}
