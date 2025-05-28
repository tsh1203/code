叒是学校周测的题目，赛时莫名其妙错了，赛后改成 lower_bound 过了，玄学。   

### 问题分析
有 $n$ 个土豆，每个土豆有对应的重量 $w_i$，土豆循环排列。不难发现，从第 $i$ 个土豆开始装的箱子的结尾与重量是固定的。根据容斥原理得知，循环节长度一定 $\le n$，即装了 $n+1$ 个土豆之后一定会出现循环。我们只需要用二分找一下终点位置，再计算出循环的每一项，即可做到 $O(1)$ 查询。

### 代码
```cpp
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,k,q,x,top; 
int w[400005],ww;
int f[200005];
int b[200005],an[200005];
int rp;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	
	rp++;
	
	cin>>n>>q>>x;
	
	for(int i=1;i<=n;i++)
	{
		cin>>w[i];
		w[i+n]=w[i];
	}
	for(int i=1;i<=2*n;i++)
	{
		w[i]+=w[i-1];
	}
	
	int qwq=w[n],now=1;
	
	for(int i=1;!f[now];i++)
	{
		top++;
		f[now]=i;
		int d=lower_bound(w,w+2*n+1,w[now-1]+x%qwq)-w;
		an[i]=(d-now+1)+x/qwq*n;
		now=d%n+1;
	}
	
	int len=top-f[now]+1;
	
	while(q--)
	{
		cin>>k;
		if(k>=f[now])
		{
			k=(k-f[now])%len+f[now];
		}
		cout<<an[k]<<endl;
	}
	return 0;
}
```
