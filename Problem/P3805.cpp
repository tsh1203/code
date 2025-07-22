#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,p[22000007],mi,r,an,l;
string s,t;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	t+="^!#";
	for(int i=0;i<s.length();i++)
		t+=s[i],t+='#';
	t+='$';
	for(int i=2;i<t.size()-1;i++){
		if(i<=r)p[i]=min(p[2*mi-i],r-i+1);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]])
			p[i]++;
		if(i+p[i]>r)mi=i,r=i+p[i]-1;
		an=max(an,p[i]);
	}
    cout<<an-1;
	return 0;
}
