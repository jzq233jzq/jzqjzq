#include<bits/stdc++.h>
using namespace std;
int nex[1000001],l1,l2;
char a[1000001],b[1000001];
int main()
{
	scanf("%s",a+1);
	scanf("%s",b+1);
	l1=strlen(a+1);l2=strlen(b+1);
	int j=0;
	for(int i=2;i<=l2;i++){
		while(j&&b[i]!=b[j+1])j=nex[j];
		if(b[i]==b[j+1])j++;
		nex[i]=j;
	}
	j=0;
	for(int i=1;i<=l1;i++){
		while(j&&a[i]!=b[j+1])j=nex[j];
		if(a[i]==b[j+1])j++;
		if(j==l2)printf("%d\n",i-l2+1),j=nex[j];
	}
	for(int i=1;i<=l2;i++)printf("%d ",nex[i]);
}