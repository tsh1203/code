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
}
using namespace FastIO;

const int N=1100006;
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
	int n,m,opt,x,last=0,ans=0;
	read(n,m);
	for(int i=1;i<=n;i++){
		read(x);
		ins(x);
	}
	while(m--){
		read(opt,x);
		x^=last;
		if(opt==1){
			ins(x);
		}
		else if(opt==2){
			del(x);
		}
		else if(opt==3){
			last=rk(x);
			ans^=last;
		}
		else if(opt==4){
			last=kth(x);
			ans^=last;
		}
		else if(opt==5){
			ins(x);
			last=val[pre()];
			ans^=last;
			del(x);
		}
		else if(opt==6){
			ins(x);
			last=val[nxt()];
			ans^=last;
			del(x);
		}
	}
	write(ans);
	return 0;
}
