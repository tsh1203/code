一道不错的题，~~居然还能写题解~~，考试时想了好久想出了用**并查集**优化此题。

本题的最大难点就是如何快速查找 $a_i$ 及其右面的第一个值为 $−1$ 的位置。

**划重点**，可以用数组 f 单独记录右侧第一个值为 $-1$ 的下标，可以简单理解为一个节点的**父亲节点**，初始化 $f_i=i$ 。

接下来只需要注意模就可以了。

可以得出：$f_i = f_{i+1} \bmod n$ 。

时间复杂度：$O(n+q)$ 。

给出代码，可以通过。

```cpp
#include<bits/stdc++.h>
#define int long long
using namespace std;
int n=1<<20,q,a[1050000],fa[1050000];
int find(int x)//板子 
{
	if(fa[x]==x)return x;
	return fa[x]=find(fa[x]);
}
signed main()
{
	for(int i=1;i<=n;i++)fa[i]=i,a[i]=-1;
	cin>>q;
	while(q--)
	{
		int t,x,p;
		cin>>t>>x;
		p=find(x%n+1);
		if(t==1)
		{
			if(a[p]==-1) a[p]=x;
			if(p==n)fa[p]=1;
			else fa[p]=p+1;
		}
		else cout<<a[x%n+1]<<endl;
	}
	return 0;
}

```

蒟蒻的第一篇题解，望通过 qwq
