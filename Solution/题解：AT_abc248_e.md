## 题意：
在 $n$ 个点中找到 $k$ 个可以连成一条**直线**的点。  

## 做法：
首先我们需要一个判断三点共线的函数：
```cpp
bool pd(int a,int b,int c)
{
	if(((x[b]-x[a])*(y[c]-y[a])==(x[c]-x[a])*(y[b]-y[a])))return 1;
	return 0;
}
```
#### 解释一下原理（我看其他题解都没有就写一写）：  
在这里，斜率可以通过两点之间的坐标差来计算。具体来说，计算 $a$ 和 $b$ 之间的斜率，以及 $a$ 和 $c$ 之间的斜率。

- $a$ 和 $b$ 之间的斜率是 $\frac{y_b - y_a}{x_b - x_a}$。
  
- $a$ 和 $c$ 之间的斜率是 $\frac{y_c - y_a}{x_c - x_a}$。

如果三点共线，那么这两条线段的斜率应该相等。

ok，现在就十分的简单了，其他题解都讲得比较清楚了，就是枚举两个点，再寻找其他共线的点，在标记一下就可以了。 

**一定要特判 $k = 1$**。

## 代码：
```cpp
#include<bits/stdc++.h>
using namespace std;
int n,k;
int x[502],y[502];
bool b[502][502];
int s[502];
int ans;
bool pd(int a,int b,int c)
{
	if(((x[b]-x[a])*(y[c]-y[a])==(x[c]-x[a])*(y[b]-y[a])))return 1;
	return 0;
}
signed main()
{
	cin>>n>>k;
	if(k==1)
	{
		cout<<"Infinity";
		return 0;
	}
	for(int i=1;i<=n;i++) 
	{
		cin>>x[i]>>y[i];
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++)
		{
			if(b[i][j]==1)continue;
			else
			{
				int qwq=1;
				s[qwq]=i;
				qwq++;
				s[qwq]=j;
				for(int xx=j+1;xx<=n;xx++)
				{
					if(pd(i,j,xx))
					{
						qwq++;
						s[qwq]=xx;
					}
				}
				for(int xx=1;xx<=qwq;xx++)
				{
					for(int yy=xx+1;yy<=qwq;yy++)
					{
						b[s[xx]][s[yy]]=1;
					}
				}
				if(qwq>=k)ans++;
			}
		}
	}
	cout<<ans;
	return 0; 
}
```
