#include<bits/stdc++.h>
using namespace std;
struct no 
{  
	int x,y,z;
};
int d,g,w;
no a[102];
int f[202][6003];
bool cmp(no x,no y)
{  
	return x.x<y.x;
}  
int main()
{  
	cin>>d>>g;
	for(int i=1;i<=g;i++)
	{
		cin>>a[i].x>>a[i].y>>a[i].z;
	}
	sort(a+1,a+g+1,cmp);
	sort(a+1,a+g+1,cmp);
	int s=10;
	for(int i=1;i<=g;i++)s+=a[i].y;
	f[0][10]=1;
	for(int w=1;w<=g;w++)
	{
		for(int i=d-1;i>=0;i--)
		{
			for(int j=s;j>=a[w].x;j--)
			{
				if(f[i][j])
				{
					if(i+a[w].z>=d)
					{
						cout<<a[w].x;
						return 0;
					}
					f[i+a[w].z][j]=1;
					f[i][j+a[w].y]=1;
				}
			}
		}
	}
	for(int i=s;i>=1;i--)
	{
		if(f[0][i])
		{
			cout<<i;
			return 0;
		}
	}
	return 0;
}
