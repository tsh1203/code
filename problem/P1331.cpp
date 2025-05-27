#include<bits/stdc++.h>
using namespace std;
int n,k,p;
int t,ans;
int s,a[110],c[200100];
int main()
{
	scanf("%d%d%d",&n,&k,&p);  
	
	for(int i=1;i<=n;i++)
	{
		scanf("%d%d",&c[i],&s);
		if(s<=p)
		{
			for(int j=i;j>t;j--) 
				a[c[j]]++;
			t=i;
			ans+=a[c[i]]-1;
		}
		else ans+=a[c[i]];
	}
	
	printf("%d",ans);
	return 0;
}
