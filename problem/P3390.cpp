#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
const int maxn=102;
const int mod=1e9+7;
struct matrix
{
	int n,m;
	int data[maxn][maxn];
	matrix(int r,int c,bool op)
	{
		n=r,m=c;
		memset(data,0,sizeof(data));
		if(op)
		{
			for(int i=0;i<n;i++)data[i][i]=1;
		}
	}
	void print()
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<this->data[i][j]<<" ";
			}
			cout<<endl;
		}
	}
	friend matrix operator * (const matrix &a,const matrix &b)
	{
		matrix c(a.n,b.m,false);
		for(int i=0;i<a.n;i++)
		{
			for(int j=0;j<b.m;j++)
			{
				for(int k=0;k<a.m;k++)
				{
					c.data[i][j]+=a.data[i][k]*b.data[k][j];
					c.data[i][j]%=mod;
				}
			}
		}
		return c;
	}
};
matrix fp(matrix a,int k)
{
	matrix ans(a.n,a.m,1);
	for(;k;k>>=1)
	{
		if(k&1)ans=ans*a;
		a=a*a;
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	int n,k;
	cin>>n>>k;
	matrix a(n,n,0);
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			cin>>a.data[i][j];	
		}
	}
	
	matrix ans=fp(a,k);
	ans.print();
	return 0;
}
