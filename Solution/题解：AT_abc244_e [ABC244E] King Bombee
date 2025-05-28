此题难处理之处就在**出现次数为偶数次**。  
经过长时间的思考后，我想到可以采用类似于状拆的思路，设计状态 $f_{i,j,k}$，表示从某点开始经过 $i$ 条边到节点 $j$，$k$ 为 $x$ 出现次数模 $2$ 的余数。  
可以得出动态转移方程：

#### 当 $(j=x)$ 时:

$dp_{i,j,1}=dp_{i,j,1}+dp_{i-1,u,0}$

$dp_{i,j,0}=dp_{i,j,0}+dp_{i-1,u,1}$

#### 当 $(j\not=x)$ 时:

$dp_{i,j,1}=dp_{i,j,1}+dp_{i-1,u,1}$

$dp_{i,j,0}=dp_{i,j,0}+dp_{i-1,u,0}$

至于建图方面就很简单了，记住是**无向图**就行了，~~尽管考试时忘了这一点调了好久~~。

给出代码：

```cpp
#include <bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,m,k,s,t,x,sum;
int f[2003][2003][10];
vector<int>e[10000];
void add(int u,int v)
{
	e[v].push_back(u); 
	e[u].push_back(v);
}
int main()
{
	cin>>n>>m>>k>>s>>t>>x;
	int a,b;
	for(int i=1;i<=m;i++)
	{
		cin>>a>>b;
		add(a,b);
	}
	f[0][s][0]=1;
	for(int i=1;i<=k;i++)
	{
		for(int j=1;j<=n;j++)
		{
			for(int k=0;k<e[j].size();k++)//遍历图 
			{
				int r=e[j][k];
				if(j==x)
				{
					f[i][j][0]+=f[i-1][r][1];
					f[i][j][1]+=f[i-1][r][0];
					f[i][j][0]%=mod;//mod
					f[i][j][1]%=mod;
				}
				else
				{
					f[i][j][0]+=f[i-1][r][0];
					f[i][j][1]+=f[i-1][r][1];
					f[i][j][0]%=mod;
					f[i][j][1]%=mod;
				}
			}
		}
	}
	cout<<f[k][t][0];
	return 0;
}
```

[提交记录](https://www.luogu.com.cn/record/192603521)
