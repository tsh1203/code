#include<bits/stdc++.h>
using namespace std;
int n,k;
int x[502],y[502];
bool b[502][502];
int s[502];
int ans;
bool pd(int a,int b,int c)
{
	if(((x[b]-x[a])*(y[c]-y[a])==(x[c]-x[a])*(y[b]-y[a])))return 1;
	return 0;
}
signed main()
{
	cin>>n>>k;
	if(k==1)
	{
		cout<<"Infinity";
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[i][j]==1)continue;
			else
			{
				int qwq=1;
				s[qwq]=i;
				qwq++;
				s[qwq]=j;
				for(int xx=j+1;xx<=n;xx++)
				{
					if(pd(i,j,xx))
					{
						qwq++;
						s[qwq]=xx;
					}
				}
				for(int xx=1;xx<=qwq;xx++)
				{
					for(int yy=xx+1;yy<=qwq;yy++)
					{
						b[s[xx]][s[yy]]=1;
					}
				}
				if(qwq>=k)ans++;
			}
		}
	}
	cout<<ans;
	return 0; 
}
