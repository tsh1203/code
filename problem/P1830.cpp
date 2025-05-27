#include<iostream>  
using namespace std;  
int n,m,t1,t2,map[2000][2000],last[2000][2000],k,i,j,x1,x2,y1,y2;  
int main()
{  
	scanf("%d%d%d%d",&n,&m,&t1,&t2);  
	for (k=1;k<=t1;k++)
	{  
		scanf("%d%d%d%d",&x1,&y1,&x2,&y2);  
		for (i=x1;i<=x2;i++)  
			for (j=y1;j<=y2;j++) 
			{  
				map[i][j]++; 
				last[i][j]=k;
			}  
	}  
	for (k=1;k<=t2;k++){  
		scanf("%d%d",&x1,&y1);  
		if (map[x1][y1]!=0) printf("Y %d %d\n",map[x1][y1],last[x1][y1]); else printf("N");  
	}  
	return 0;
}
