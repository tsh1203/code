#include<bits/stdc++.h>
using namespace std;
int main()
{
	int r1[4],r2[4];
	for(int i=0;i<4;i++)
	{
		cin>>r1[i];
	}
	for(int i=0;i<4;i++)
	{
		cin>>r2[i];
	}
	int count=0;
	for(int i=0;i<4;i++)
	{
		for(int j=i+1;j<4;j++)
		{
			if((r1[i]<r1[j]&&r2[i]>r2[j])||(r1[i]>r1[j]&&r2[i]<r2[j]))
			{
				count++;
			}
		}
	}
	cout<<count;
	return 0;
}
