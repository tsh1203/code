cout<<fixed<<setprecision(2)<<x1<<" ";
#include <bits/stdc++.h>
using namespace std;
bool a[30010];
int ma,n,i,k,x,t;
int main()
{
	scanf("%d%d",&n,&k);
	for(i=1;i<=n;i++)
	{
		scanf("%d",&x);
		if(!a[x]){a[x]=1;t++;ma=max(ma,x);}          
	}
	if(t<k)
	{
		printf("NO RESULT");
		return 0;
		
	}
	for(i=1;i<=ma;i++)
	{
		if(a[i]) k--;
		if(!k) {printf("%d",i);return 0;}
	}
	return 0;
}
