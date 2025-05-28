### 大致思路：
题目意思简单明了，求出至少需要多少种不同的权值其实就是找出度数最大的节点，可以轻松求出。

本题的难点（其实也不难）在于如何求出方案，此处我们将本体视作一个涂色问题，这一点其他题解讲的已经很明白了，不多做叙述。

这里的方法很多，我使用的是 DFS，从任意节点（我选择 1 号节点）出发，跑一遍 DFS，使一个节点的相邻节点没有相同的颜色即可。

### 代码：
```cpp
#include <bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,ans=INT_MIN,an[100005],k;
int to[100005],nxt[100005];
int head[100005],a[100005];
void add(int x,int y)
{
	k++;
	to[k]=y;
	nxt[k]=head[x];
	head[x]=k;
	a[x]++,a[y]++;
}
void dfs(int x,int y)
{
	int s=0;
	for(int i=head[x];i;i=nxt[i])
	{
		s++;
		an[i]=s;
		if(s==y)
		{
			s++;
			an[i]=s;
		}
		dfs(to[i],an[i]);
	}
}
signed main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		ans=max(ans,max(a[x],a[y]));
	}
	cout<<ans<<endl;
	dfs(1,0);
	for(int i=1;i<n;i++)
	{
		cout<<an[i]<<endl;
	}
	return 0;
}
```
码风比较丑陋，将就看吧 qwq。
