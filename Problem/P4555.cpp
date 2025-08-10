#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD=19930726;
const int N=2e6+6;
int n,k,p[N],mi,r,an=1,l;
int cnt[N];
int ll[N],rr[N];
string s,t;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	n=s.length()-1;
	t+="^!#";
	for(int i=0;i<=n;i++)
		t+=s[i],t+='#';
	t+='$';
	n=t.size()-1;
	for(int i=2;i<(int)t.size()-1;i++){
		if(i<=r)p[i]=min(p[2*mi-i],r-i+1);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]])
			p[i]++;
		if(i+p[i]>r)mi=i,r=i+p[i]-1;
		ll[i-p[i]+1]=max(ll[i-p[i]+1],p[i]-1);
		rr[i+p[i]-1]=max(rr[i+p[i]-1],p[i]-1);
	}
	for(int i=n;i>=2;i-=2)rr[i]=max(rr[i],rr[i+2]-2);
	for(int i=2;i<=n;i+=2)ll[i]=max(ll[i],ll[i-2]-2);
	for(int i=2;i<=n;i+=2)
		if(rr[i]&&ll[i])
			an=max(an,ll[i]+rr[i]);
	cout<<an;
	return 0;
}
