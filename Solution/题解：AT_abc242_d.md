### 大致题意：
有一个字符串，每次操作会将 A 改为 BC，B 改为 AC，C 改为 AB。  
然后我们就可以发现，**这怎么像个二叉树呢？**    
![](https://cdn.luogu.com.cn/upload/image_hosting/iqwld53g.png)   
现在我们要做的就是，根据输入的 $t_i$ 与 $k_i$ 求出其根节点，再逆着求一次。  
还有一个非常重要的点，就是因为数据范围是 $k_i \le  10 ^ {18} $，所以要加特判。

### 代码：
```cpp
#include<bits/stdc++.h>
#pragma GCC optimize("3","Ofast","inline")
#define int long long
#define endl "\n"
using namespace std;
string s;
int q,a,b,x,y;
signed main()
{
	//log(1e18)=59.7947
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	cin>>q;
	for(int i=0;i<(int)s.length();i++)s[i]-='A';
	while(q--)
	{
		cin>>x>>y;
		if(x>60)
		{
			a=0;
			b=y-1;
		}
		else
		{
			a=(y-1)/(1ll<<x);
			b=(y-1)%(1ll<<x);
		}
		int c=(s[a]+x)%3;
		for(int i=b;i>0;i-=(i&-i))
		{
			c++;
			c%=3;
		}
		cout<<(char)(c+'A')<<endl;
	}
	return 0;
}
```
