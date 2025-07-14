#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int m,d;
int a[200005],t,cnt;
int k,s[200005],ans[2003];
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	memset(ans,128,sizeof ans);
	
	cin>>m>>d;
	k=sqrt(m/2);
	for(int i=1;i<=m;i++)
		s[i]=(i-1)/k+1;
	while(m--){
		char op;
		int x;
		cin>>op>>x;
		if(op=='A'){
			a[++cnt]=(t+x)%d;
			ans[s[cnt]]=max(ans[s[cnt]],a[cnt]);
		}
		else{
			int l=cnt-x+1,r=cnt;
			t=INT_MIN;
			for(int i=s[l]+1;i<s[r];i++)
				t=max(t,ans[i]);
			for(int i=l;i<=s[l]*k;i++)
				t=max(t,a[i]);
			if(s[l]!=s[r])
				for(int i=(s[r]-1)*k;i<=r;i++)
					t=max(t,a[i]);
			cout<<t<<endl;
		}
	}
	return 0;
}
