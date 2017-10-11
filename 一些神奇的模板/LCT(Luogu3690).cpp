#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<iostream>
#include<cstdlib>
#include<string>
#include<ctime>
#include<queue>
#include<climits>
using namespace std;
int t[100001][2],fa[100001],la[100001];
int n,m,zh[100001],v[100001],s[100001];
inline void pushup(int x){s[x]=v[x]^s[t[x][0]]^s[t[x][1]];}
inline void pushdown(int x){
	if(la[x]){
		swap(t[x][1],t[x][0]);
		la[t[x][1]]^=1;la[t[x][0]]^=1;
	}
	la[x]=0;
}
inline bool rt(int x){
	return t[fa[x]][0]!=x&&t[fa[x]][1]!=x;
}
inline void turn(int x){
	int y=fa[x],z=fa[y],l=(x!=t[fa[x]][0]),r=(y!=t[fa[y]][0]);
	int p=t[x][l^1];
	if(!rt(y))t[z][r]=x;
	fa[p]=y;fa[x]=z;t[x][l^1]=y;fa[y]=x;t[y][l]=p;
	pushup(y);pushup(x);
}
inline void splay(int x){
	int i=x,y,z;for(;!rt(i);i=fa[i])zh[++zh[0]]=i;
	zh[++zh[0]]=i;while(zh[0])pushdown(zh[zh[0]--]);
	while(!rt(x)){
		y=fa[x];z=fa[y];
		if(!rt(y)){
			if((t[y][0]==x)^(t[z][0]==y))turn(x);
			else turn(y);
		}
		turn(x);
	}
}
inline void access(int x){
	int p=0;
	while(x){
		splay(x);t[x][1]=p;
		p=x;pushup(x);x=fa[x];
	}
}
inline void chrt(int x){
	access(x);splay(x);la[x]^=1;
}
inline void link(int x,int y){
	chrt(x);fa[x]=y;
}
inline void cut(int x,int y){
	chrt(x);access(y);splay(y);
	t[y][0]=fa[x]=0;
}
inline int askrt(int x){
	access(x);splay(x);int p=x;pushdown(x);
	while(t[p][0])p=t[p][0],pushdown(p);
	return p;
}
int main()
{
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",&v[i]),s[i]=v[i];
	for(int i=1;i<=m;i++){
		int p,x,y;scanf("%d%d%d",&p,&x,&y);
		if(p==0){
			chrt(x);access(y);splay(y);
			printf("%d\n",s[y]);
		}
		if(p==1){
			int xx=askrt(x),yy=askrt(y);if(xx!=yy)link(x,y);
		}
		if(p==2){
			int xx=askrt(x),yy=askrt(y);if(xx==yy)cut(x,y);
		}
		if(p==3){
			access(x);splay(x);v[x]=y;pushup(x);
		}
	}
	return 0;
}