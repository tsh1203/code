## 前言
~~DFS 我会，但这加了个序这变成啥玩意~~

因为我学的也不是很懂，所以有部分借鉴了老师的讲义。

## 介绍
**DFS 序**就是将树的节点按照**先序遍历**的顺序 DFS 遍历得到的时间戳序列，可以将树形结构转换成线性问题。因为一棵树的 DFS 序全在一个连续的区间里，所以可以与线段树与树状数组搭配使用（tsh：为什么线段树都来了没有[分块](https://tsh1203.github.io/)，差评），说白了，就是在 DFS 序上建立**线段树**和**树状数组**。

核心代码：
```cpp
void dfs(int u,int fa)
{
	st[u]=++tim;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)
		{
			dfs(v,u);
		}
	}
	en[u]=tim;
}
```
其实就是在 DFS 里加两行代码。

## 性质
以上面的代码为例，$st[x]$ 表示第一次遍历到 $x$ 节点的时间戳，$en[x]$ 表示从 $x$ 节点推出时的时间戳。不难发现，以 $x$ 为根的子树在 DFS 序中就是区间 $[st[x],en[x]]$。这棵树的所有子节点就是这段区间内的所有节点。

## 模板
让我们看一道模板题（真的是模板）。

---
**题目描述**

一颗有 $n$ 个结点的苹果树，根为 $1$，每个结点最多只有一个苹果，给出 $n-1$ 个结点的关系和给出 $m$ 个操作，每个操作有如下两种类型：

Q $x$ 表示询问 $x$ 的子树（包括 $x$）苹果的数量，

C $x$ 表示若分支 $x$ 上有苹果，则摘下来，若没有则会生出一个。

输出每个询问的值。

**输入格式**

第一行一个整数 $n(1<=n<=100000)$，表示苹果树上树杈的数量

接下来 $n-1$ 行，每行两个整数u,v,表示苹果树上的一条边

接下来一行一个整数 $m(1 \le m \le 100000)$

接下来 $m$ 行，每行表示一个操作（两种类型的操作之一）

**输出格式**

对于每个询问的操作，输出一个值

---

~~话说为什么这苹果会自己长出来~~

有个同学在做了这道题之后把聊天群名字改成了 Apple Tree。

让我们看一下题，题目说的很明白，就是有一棵树，每一次将一个节点进行修改，再查询子树和。

首先想到暴力，但是 $1\le n,m \le 100000$。一眼不行，所以 **DFS序**，启动！

**代码：**
```cpp
#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,p,cnt,tim;
int head[1000006];
int st[1000006],en[1000006],a[1000006],s[1000006];
struct ed
{
	int v,nxt;
}e[2000006];
int lb(int x)
{
	return x&-x;
}
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	st[u]=++tim;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)
		{
			dfs(v,u);
		}
	}
	en[u]=tim;
}
void pchange(int x,int y)
{
	for(int i=x;i<=n;i+=lb(i))
	{
		s[i]+=y;
	}
}
int sum(int x)
{
	int ans=0;
	for(int i=x;i;i-=lb(i))
	{
		ans+=s[i];
	}
	return ans;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=1;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	for(int i=1;i<=n;i++)
	{
		pchange(st[i],a[i]);
	}
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		char op;
		int x;
		cin>>op>>x;
		if(op=='C')
		{
			if(a[x]==1)
			{
				pchange(st[x],-1);
				a[x]=0;
			}
			else
			{
				pchange(st[x],1);
				a[x]=1;
			}
			
		}
		else
		{
			cout<<sum(en[x])-sum(st[x]-1)<<endl;
		}
	}
	return 0;
}
```

为了弘扬[分块](https://tsh1203.github.io/posts/2024/1021)的传统，所以我又写了一份分块的。

```cpp
#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
int n,m,p,cnt,tim;
int head[1000006];
int st[1000006],en[1000006],a[1000006];
int k;
int s[1000006],ans[1003];
struct ed
{
	int v,nxt;
}e[2000006];
void add(int u,int v)
{
	e[++cnt].v=v;
	e[cnt].nxt=head[u];
	head[u]=cnt;
}
void dfs(int u,int fa)
{
	st[u]=++tim;
	for(int i=head[u];i;i=e[i].nxt)
	{
		int v=e[i].v;
		if(v!=fa)
		{
			dfs(v,u);
		}
	}
	en[u]=tim;
}
void init()
{
	k=sqrt(n);
	for(int i=1;i<=n;i++)
	{
		s[i]=(i-1)/k+1;
		ans[s[i]]+=a[i];
	}
}
void pchange(int x)
{
	a[x]^=1;
	ans[s[x]]+=a[x]?1:-1;
}
int sum(int l,int r)
{
	int an=0;
	for(int i=l;i<=min(s[l]*k,r);i++)an+=a[i];
	if(s[l]!=s[r])
	{
		for(int i=s[l]+1;i<s[r];i++)an+=ans[i];
		for(int i=(s[r]-1)*k+1;i<=r;i++)an+=a[i];
	}
	return an;
}
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>n;
	for(int i=1;i<=n;i++)a[i]=1;
	for(int i=1;i<n;i++)
	{
		int x,y;
		cin>>x>>y;
		add(x,y);
		add(y,x);
	}
	dfs(1,0);
	init();
	cin>>m;
	for(int i=1;i<=m;i++)
	{
		char op;
		int x;
		cin>>op>>x;
		if(op=='C')
		{
			pchange(st[x]);
			
		}
		else
		{
			cout<<sum(st[x],en[x])<<endl;
		}
	}
	return 0;
}
```
本来想放个莫队的发现不会带修莫队，看下一题吧。
## 后记
吐槽：DFS 序好恶心啊，一共 7 种模型，根本不是人。

DFS 序我到现在还没完全学懂，这道模板题是点修改，子树查询，属于最简单的一种。之后学懂了再来慢慢补上。