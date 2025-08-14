## 前言
是有一堆水蓝的 [manacher](https://oi-wiki.org/string/manacher/)！（真的比 [kmp](https://oi-wiki.org/string/kmp/) 简单）

## 简介
该算法由 **Glenn K. Manache** 在 1975 年提出，在解决回文串问题上有非常优秀的表现，码量很短且时间与空间复杂度的常数更小。经常被 OIer 们戏称为**马拉车**。

## 实现
以[模板题](https://www.luogu.com.cn/problem/P3805)为例。

题意非常简单明了，就是求一个字符串中最长回文串的长度，不知道回文串是什么的可以洗洗睡了。

### 朴素暴力
最简单的方法就是 $O(n^2)$ 暴力枚举字串的范围，再 $O(n)$ 判断是否是回文串，总的时间复杂度为 $O(n^3)$，然后我们就获得了 18 pt 的“好成绩”。

[提交记录](https://www.luogu.com.cn/record/230080939)。

### 中心扩展法
这种暴力的核心原理就是分类讨论回文串长度的奇偶性，把字符串的每个字符或每两个相同的字符看作中心，然后左右扩展检查，判断它左右的对称位置是否相同，若相同，则是回文的一部分，直到对称位置不同为止。

这种方法的时间复杂度为 $O(n^2)$，稍微好了一点，66 pt。

[提交记录](https://www.luogu.com.cn/record/230083188)。

### manacher
进入正题，可以发现题目的数据范围为 $1\le n\le 1.1×10^7$，考虑 $O(n)$ 实现。

我们简单做一些定义。

**原串 S**：读入的字符串 S。  

**扩展串 T**：在 S 的每个字符左右插人一个**不属于** S 的字符，如`#`，记为字符串 T，这样转换的目的是不用考虑偶数长度的回文串。

例子：
```
S：abcba  
T：#a#b#c#b#a#
```
**回文中心 c**：在扩展串 T 中，以字符 c 作为回文串的中心。

**回文半径数组P**：$P_i$ 表示以字符 T[i] 为回文中心的最长回文的**半径**。

偷一张讲义上的图：

![](https://cdn.luogu.com.cn/upload/image_hosting/d8l1nf9o.png)

manacher 的实现难度不大，中心扩展法低效的原因是有重复的检查，manacher算法的核心思想是利用**回文的镜像也是回文**这个特征减少重复检查。

~~是不是有点抽象~~，同样挂张图。

![](https://cdn.luogu.com.cn/upload/image_hosting/xx8muyrn.png)

图中 i 与 j 关于 $c$ 对称，若 i 为回文串，那么 j 也一定为回文串，我们可以利用这个特性进行优化。

为了快速计算，我们记已找到的最靠右的子回文串的边界 $r$，也可以表示成是取 T 的前 $i$ 个点中下回文半径能够向右延伸的最大下标。

为了方便，我们定义 $i$ 关于 $c$ 的对称点为 $d$，且易得 $d=2\times c-i$。

$p_i$ 的求解需要分类讨论一下。

- 对于 $i>r$，暴力求解 $p_i$
- 对于 $i\le r$，
  $$
  p_i = \begin{cases}
  p_d & (d-p_d+1)>(c-p_c+1) \\
  \min=r-i+1 \text{，并继续向后匹配} & (d-p_d+1)=(c-p_c+1) \\
  r-i+1 & (d-p_d+1)<(c-p_c+1) \\
  \end{cases}
  $$

有点抽象，挂一段核心代码辅助理解，可以按需修改
```cpp
for(int i=2;i<t.size()-1;i++){
    if(i<=r)p[i]=min(p[2*mi-i],r-i+1);
    else p[i]=1;
    while(t[i-p[i]]==t[i+p[i]])
        p[i]++;
    if(i+p[i]>r)mi=i,r=i+p[i]-1;
    an=max(an,p[i]);
}
```

## 完整代码：
```cpp
#include<bits/stdc++.h>
#define int long long
#define endl "\n"
using namespace std;
int n,p[22000007],mi,r,an,l;
string s,t;
signed main()
{
	ios::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
	cin>>s;
	t+="^!#";
	for(int i=0;i<s.length();i++)
		t+=s[i],t+='#';
	t+='$';
	for(int i=2;i<t.size()-1;i++){
		if(i<=r)p[i]=min(p[2*mi-i],r-i+1);
		else p[i]=1;
		while(t[i-p[i]]==t[i+p[i]])
			p[i]++;
		if(i+p[i]>r)mi=i,r=i+p[i]-1;
		an=max(an,p[i]);
	}
    cout<<an-1;
	return 0;
}
```

[借用 WL 大佬的例题参考代码](https://www.luogu.com/article/fh4izofe)，需要题目的里面也有一些。

## 参考资料
- 老师发的讲义
- [OI Wiki](https://oi-wiki.org/string/manacher/)
- 文章广场的部分博客：
  - https://www.luogu.com.cn/article/rs0bgnw5
  - https://www.luogu.com.cn/article/nj5k91wu
  - https://www.luogu.com.cn/article/5plkunsd
