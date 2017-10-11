#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <iostream>
#include <ctime>
#include <map>
#include <queue>
#include <cstdlib>
#include <string>
#include <climits>
#include <set>
#include <vector>
using namespace std;
char c[1000001],s[1000001];
int np=0,ans,b[1000001],p[1000010][26],q[1000001],fail[1000001],rt=0;
inline void insert(char c[],int x){
	int now=0,l=strlen(c+1);
	for(int i=1;i<=l;i++){
		int t=c[i]-'a';
		if(!p[now][t])p[now][t]=++np;
		now=p[now][t];
	}
	b[now]++;
}
inline void bfs(){
	int l=1,r=1;q[1]=rt;fail[rt]=0;
	while(l<=r){
		int now=q[l++];int pp=0;
		for(int i=0;i<26;i++)if(p[now][i]){
			q[++r]=p[now][i];
			if(now==rt){fail[p[now][i]]=rt;continue;}
			pp=fail[now];
			while(pp)if(p[pp][i]){fail[p[now][i]]=p[pp][i];break;}
				else pp=fail[pp];
			if(!pp)if(p[pp][i])fail[p[now][i]]=p[pp][i];
				else fail[p[now][i]]=rt;
		}
	}
}
inline void check(){
	int now=0,l=strlen(c+1);
	for(int i=1;i<=l;i++){
		int t=c[i]-'a';
		while(!p[now][t]&&now)now=fail[now];
		now=p[now][t];
		for(int tt=now;tt&&b[tt]!=-1;tt=fail[tt])ans+=b[tt],b[tt]=-1;
	}
}
int main()
{
	int n;scanf("%d",&n);
	for(int i=1;i<=n;i++){
		scanf("%s",s+1);
		insert(s,i);
	}
	bfs();
	scanf("%s",c+1);check();
	printf("%d",ans);
	return 0;
}