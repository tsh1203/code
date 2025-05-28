/*给出两个字符串s1和s2,若S1的区间[L,R]子串与s2完全相同，则称s2在s1中出现了，其出现位置为L.现在请你求出s2在s1中所有出现的位置。
定义一个字符串s的border为s的一个非s本身的子串t,满足t既是s的前缀，又是s的后缀。对于s2,你还需要求出对于其每个前缀s’的最长border t'的长度。

*/

#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,nxt[1000006];
string a,b;
signed main()
{
	cin>>a>>b;
	n=a.length();
	m=b.length();
	for(int i=1,j=0;i<m;i++)
	{
		j=nxt[i];
		while(j&&b[i]!=b[j])j=nxt[j];
		if(b[i]==b[j])nxt[i+1]=j+1;
	}
	for(int i=0,j=0;i<n;i++)
	{
		while(j&&a[i]!=b[j])j=nxt[j];
		if(a[i]==b[j])j++;
		if(j==m)
		{
			cout<<i-m+2<<endl;
		}
	}
	for(int i=1;i<=m;i++)cout<<nxt[i]<<" ";
	return 0;
}
