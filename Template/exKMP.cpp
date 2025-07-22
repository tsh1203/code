#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int N=1e5+5;
string s;
int n,r,p,l[N];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	s=" "+s; 
	n=s.length();
	for(int i=2;i<=n;i++){
		if(r>=i)
			l[i]=min(l[i-p+1],r-i+1);
		while(i+l[i]<=n&&s[i+l[i]]==s[l[i]+1])
			l[i]++;
		if(i+l[i]-1>r)
			r=i+l[i]-1,p=i;
	}
	for(int i=1;i<n;i++)
		cout<<l[i]<<" ";
	return 0;
}
