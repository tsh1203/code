#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int mod=1e9+7;
int t,nxt[1000010],ans[1000010];
int cnt;
string s;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
    cin>>t;
    while(t--){
    	memset(nxt,0,sizeof nxt);
        int j=0;
		ans[0]=0,ans[1]=1;
		
        cin>>s;
        for(int i=1;i<s.size();i++){
            while(j&&(s[i]!=s[j]))j=nxt[j];
            j+=(s[i]==s[j]);nxt[i+1]=j;
			ans[i+1]=ans[j]+1;
        }
        
        j=0,cnt=1;
        for(int i=1;i<s.size();i++){
            while(j&&(s[i]!=s[j]))j=nxt[j];
            j+=(s[i]==s[j]);
            while((j<<1)>(i+1))j=nxt[j];
            cnt=cnt*(ans[j]+1)%mod;
        }
        cout<<cnt<<endl;
    }
}
