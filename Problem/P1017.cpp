#include<bits/stdc++.h>
using namespace std;
char z[20]={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G','H','I','J'}; 
void zhuan(int n,int m)
{
	if(n!=0)
	{
		if(n>0||n%m==0)
		{
			zhuan(n/m,m);
			printf("%c",z[n%m]);
		}
		else 
		{
			zhuan(n/m+1,m);
			printf("%c",z[-m+n%m]);
			
		}
	}
	return;
}
int main()
{
	int n,m;
	scanf("%d%d",&n,&m);
	printf("%d=",n);
	zhuan(n,m);
	printf("(base%d)",m);
	return 0;
}
