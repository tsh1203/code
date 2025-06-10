#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int p=233317,mod=1000000007;
int n,k,base[200005];
string s[500005];
vector<int>h[500005];
map<int,int>m;
int poww(int x,int y){
	int ans=1;
	while(y){
		if(y%2==1)ans=ans*x;
		x=x*x;
		y>>=1;
	}
	return ans;
}
void has(string st,int x){
	h[x].push_back(0);
	int y=0;
	for(int i=0;i<st.length();i++){
		y*=p;
		y+=st[i]-'a'+1;
		h[x].push_back(y);
	}
}
int hs(int l,int r,int x){
	return h[x][r]-h[x][l-1]*base[r-l+1];
}
signed main(){
	cin>>n;
	base[0]=1;
	for(int i=1;i<=2*n;i++)
		base[i]=base[i-1]*p%mod;
	
	for(int i=1;i<=n;i++){
		cin>>s[i];
		has(s[i],i);
		for(int j=0;j<s[i].length();j++)
			m[hs(1,j+1,i)]++;
	}
	
	for(int i=1;i<=n;i++){
		int ans=0;
		for(int j=0;j<s[i].length();j++){
			if(m[hs(1,j+1,i)]>1)ans=j+1;
			else break;
		}
		cout<<ans<<endl;
	}
	return 0;
}
