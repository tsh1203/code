#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std; 
int n,m; 
string s,t; 
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	cin>>s>>t; 
	n=s.length(),m=t.length(); 
	int cnt=0; 
	for(int i=0;i<m;++i)    
	{ 
		if(s[n-m+i]!='?'&&t[i]!='?'&&s[n-m+i]!=t[i])
		{ 
			cnt++; 
		} 
	} 
	if(cnt==0)
	{ 
		cout<<"Yes"<<endl; 
	}
	else
	{ 
		cout<<"No"<<endl; 
	} 
	for(int i=0;i<m;i++)
	{ 
		if(s[i]!='?'&&t[i]!='?'&&s[i]!=t[i])
		{ 
			cnt++; 
		} 
		if(s[n-m+i]!='?'&&t[i]!='?'&&s[n-m+i]!=t[i])
		{ 
			cnt--; 
		} 
		if(cnt==0)
		{ 
			cout<<"Yes"<<endl; 
		}
		else
		{ 
			cout<<"No"<<endl; 
		} 
	} 
	return 0; 
} 
