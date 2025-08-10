#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int MOD=19930726;
const int N=2e6+6;
int n,k,p[N],mi,r,an=1,l;
int cnt[N];
string s,t;
int fp(int a,int b){
	int res=1;
	while(b){
		if(b&1)res=res*a%MOD;
		a=a*a%MOD;
		b>>=1;
	}
	return res;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n>>k;
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
		if((p[i]-1)%2)cnt[p[i]-1]++;
	}
	int sum=0;
	for(int i=n;i>=1;i--){
		if(i%2==0)continue;
		sum+=cnt[i];
		if(k>=sum){
			an=(an*fp(i,sum))%MOD;
			k-=sum;
		}
		else{
			an=(an*fp(i,k))%MOD;
			k-=sum;
			break;
		}
	}
	if(k>0)an=-1;
	cout<<an;
	return 0;
}
