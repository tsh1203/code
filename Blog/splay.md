拉伸！

![](https://cdn.luogu.com.cn/upload/image_hosting/0pjb8m3y.png)

（Splay 树又称伸展树，所以拉伸）

恶心人的东西，写出来比 [fhq treap](http://tsh1203.github.io/posts/2024/1029) 长了 30 行，但是比某后缀数组好学得多。

## 定义

Splay 树又称伸展树（上文提到了），是一种平衡二叉查找树，由 Daniel Sleator 和 Robert Tarjan 于 1985 年发明。

Splay 树核心原理是通过伸展操作将某个节点旋转到根节点，使得他能够在均摊 $O(\log n)$ 的时间复杂度内完成平衡树得若干操作。

为了使 Splay 树保持平衡，我们需要进行旋转操作（抽象至极），将某个点向上移动一个位置，并且保持 Splay 的二叉搜索树性质不变。

## 基本操作
旋转分为左旋和右旋，但本质上没什么区别。

设当前结点为 x，父亲结点是 y，y 的父亲为 z，且旋转是右旋：
1. 更新父亲与儿子信息：将 y 的左儿子标记为 x 的右儿子，x 的右儿子标记为 y，若 z 存在，将 z 对应的儿子标记成 x。（**父亲节点的信息也要一同更改**）
2. 更新结点信息：先 y 再 x 最后到 z。

需要注意一点：所有操作都要**至下而上**进行。

左旋反之，不做叙述。

借用一张 OI Wiki 上的图片：
![](https://oi-wiki.org/ds/images/splay-zig.svg)

旋转的实现（$ch$ 数组是左右儿子）：
```cpp
void rotate(int x){
	int y=fa[x],z=fa[y],s=pd(x);
	son[y][s]=son[x][s^1];
	if(son[x][s^1])fa[son[x][s^1]]=y;
	son[x][s^1]=y;
	fa[y]=x;
	fa[x]=z;
	if(z)son[z][y==son[z][1]]=x;
	maintain(y);
	maintain(x);
}
```

那旋转有啥用啊？

别忘了，Splay 的核心操作是**伸展操作**，求每访问一个节点 x 都要将其旋转到根节点（我也不知道为什么）。

但是我们不能每次将 x 向上旋转一层，非常容易被毒瘤数据卡，这样的数据构造也不难，只需要使得平衡树被构造为一条链即可。

所以我们需要用到**双旋**（以上介绍的旋转操作为单旋）。

我们设当前结点是 x，父亲是 p，p 的父亲是 g，分类讨论一下：

### zig

对于 p 为根节点的情况（即 g 不存在），我们直接旋转 x 即可。

![](https://cdn.luogu.com.cn/upload/image_hosting/82jhu7on.png)

### zig zig

若 x - p - g 为直链（即是同侧儿子），我们先将 p 向上旋转一次，再将 x 也旋转一次。

![](https://cdn.luogu.com.cn/upload/image_hosting/rs415h9o.png)

### zig zag

若 x - p - g 不是直链，我们直接将 x 向上旋转两次。

![](https://cdn.luogu.com.cn/upload/image_hosting/owi1s77t.png)


判断使用哪种旋转的话我们只需要判断是左儿子还是右儿子即可，实现不难，不放代码了。

## 时间复杂度

老师讲了 40min 愣是没听懂，只记得单次均摊复杂度是 
$O(\log n)$ 的，具体可以看 [OI Wiki](https://oi-wiki.org/ds/splay/#%E6%97%B6%E9%97%B4%E5%A4%8D%E6%9D%82%E5%BA%A6)。

## 平衡树操作
Splay 可以实现普通平衡树的各种操作，大致和普通二叉搜索树一样，只多了一步 splay 到根。
1. 查找单个结点：无论按照值还是排名找，只需在二叉搜索树上找到那个结点然后将其 splay 到根就行了。
2. 插入单个结点：只需要在二叉搜索树上找到对应位置插
入后将其 splay 到根。
3. 删除单个结点：先找到对应结点，splay 到根，删除它后我们得到了两棵 splay 树，只需将右子树的权值最小的结点 splay 到根，将左子树插入到右子树的左儿子。
4. 查排名：额外记录每个结点的子树大小，然后找单个结点的同时计算排名，记得查询完后 splay 到根。
5. 查前驱/后继：直接在对应二叉搜索树上查询即可，记得最后 splay 到根。

Q：为什么要 splay 到根啊？    
A：我不知道啊。

区间操作没学会，回头补上。

## 代码
[P3369](https://www.luogu.com.cn/problem/P3369) AC 代码（有亿点点长）。
```cpp
#include<bits/stdc++.h>
#define int long long
#ifdef __linux__
#define getchar getchar_unlocked
#define putchar putchar_unlocked
#else
#define getchar _getchar_nolock
#define putchar _putchar_nolock
#endif
using namespace std;
namespace FastIO {
	void read(){}
	template <class T1,class ... T2> inline void read(T1 &x,T2 &... oth){
		bool pd=0;x=0;char ch=getchar();
		while(!isdigit(ch)){pd|=ch=='-';ch=getchar();}
		while(isdigit(ch)){x=(x<<3)+(x<<1)+(ch^48);ch=getchar();}
		x=pd?-x:x;
		read(oth...);
	}
	template <class T> void _write(T x){
		if(x<0){putchar('-');x=-x;}
		if(x>9) _write(x/10);
		putchar(x%10^48);
	}
	void write(){}
	template <class T1,class ... T2>
	inline void write(T1 x,T2 ...oth){_write(x);putchar('\n');write(oth...);}
	inline void endline(){putchar('\n');}
}//Orz lby 
using namespace FastIO;

const int N=100005;
int rt,tot,fa[N],ch[N][2],val[N],cnt[N],sz[N];

void maintain(int x){
	sz[x]=sz[ch[x][0]]+sz[ch[x][1]]+cnt[x];
}
bool get(int x){
	return x==ch[fa[x]][1];
}
void clear(int x){
	ch[x][0]=ch[x][1]=fa[x]=val[x]=sz[x]=cnt[x]=0;
}
void rotate(int x){
	int y=fa[x],z=fa[y],chk=get(x);
	ch[y][chk]=ch[x][chk^1];
	if(ch[x][chk^1])fa[ch[x][chk^1]]=y;
	ch[x][chk^1]=y;
	fa[y]=x;
	fa[x]=z;
	if(z)ch[z][y==ch[z][1]]=x;
	maintain(y);
	maintain(x);
}
void splay(int x){
	for(int i=fa[x];i=fa[x],i;rotate(x)){
		if(fa[i]){
			if(get(x)==get(i))rotate(i);
			else rotate(x);
		}
	}
	rt=x;
}

void ins(int k){
	if(!rt){
		val[++tot]=k;
		cnt[tot]++;
		rt=tot;
		maintain(rt);
		return;
	}
	int cur=rt,f=0;
	while(1){
		if(val[cur]==k){
			cnt[cur]++;
			maintain(cur);
			maintain(f);
			splay(cur);
			break;
		}
		f=cur;
		cur=ch[cur][val[cur]<k];
		if(!cur){
			val[++tot]=k;
			cnt[tot]++;
			fa[tot]=f;
			ch[f][val[f]<k]=tot;
			maintain(tot);
			maintain(f);
			splay(tot);
			break;
		}
	}
}
int rk(int k){
	int res=0,cur=rt;
	while(1){
		if(k<val[cur])
			cur=ch[cur][0];
		else{
			res+=sz[ch[cur][0]];
			if(!cur)return res+1;
			if(k==val[cur]){
				splay(cur);
				return res+1;
			}
			res+=cnt[cur];
			cur=ch[cur][1];
		}
	}
}
int kth(int k){
	int cur=rt;
	while(1){
		if(ch[cur][0]&&k<=sz[ch[cur][0]])
			cur=ch[cur][0];
		else{
			k-=cnt[cur]+sz[ch[cur][0]];
			if(k<=0){
				splay(cur);
				return val[cur];
			}
			cur=ch[cur][1];
		}
	}
}
int pre(){
	int cur=ch[rt][0];
	if(!cur)return cur;
	while(ch[cur][1])
		cur=ch[cur][1];
	splay(cur);
	return cur;
}
int nxt(){
	int cur=ch[rt][1];
	if(!cur)return cur;
	while(ch[cur][0])
		cur=ch[cur][0];
	splay(cur);
	return cur;
}
void del(int k){
	rk(k);
	if(cnt[rt]>1){
		cnt[rt]--;
		maintain(rt);
		return;
	}
	if(!ch[rt][0]&&!ch[rt][1]){
		clear(rt);
		rt=0;
		return;
	}
	if(!ch[rt][0]){
		int cur=rt;
		rt=ch[rt][1];
		fa[rt]=0;
		clear(cur);
		return;
	}
	if(!ch[rt][1]){
		int cur=rt;
		rt=ch[rt][0];
		fa[rt]=0;
		clear(cur);
		return;
	}
	int cur=rt,x=pre();
	fa[ch[cur][1]]=x;
	ch[x][1]=ch[cur][1];
	clear(cur);
	maintain(rt);
}
signed main(){
	
	int n,opt,x;
	read(n);
	while(n--){
		read(opt,x);
		if(opt==1)ins(x);
		else if(opt==2)del(x);
		else if(opt==3)write(rk(x));
		else if(opt==4)write(kth(x));
		else if(opt==5)ins(x),write(val[pre()]),del(x);
		else ins(x),write(val[nxt()]),del(x);
	}
	return 0;
}
```

## 练习
[神秘的题单。](https://www.luogu.com.cn/training/811158)

以及**一定**要记住数组要开到 $n+m$（$n$ 为初始的节点数，$m$ 为操作数）！！！

## 参考资料

- 老师给的课件
- [OI Wiki](https://oi-wiki.org/ds/splay)

## 特别鸣谢
- [czz](https://www.luogu.com.cn/user/58363)：教练
- [zxx](https://www.luogu.com.cn/user/1167457)：帮忙整理了题单。
- [WL](https://www.luogu.com.cn/user/851495)：帮忙检查纰漏。
