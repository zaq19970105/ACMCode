using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

//HDU 1698

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 111111;
int sumn[maxn<<2];
int tag[maxn<<2];

int pushUp(int rt){
	sumn[rt] = sumn[rt<<1] + sumn[rt<<1|1];
	return 0;
}

int pushDown(int rt,int m){
	if(tag[rt]){
		tag[rt<<1] = tag[rt<<1|1] = tag[rt];
		sumn[rt<<1] = tag[rt]*(m-(m>>1));
		sumn[rt<<1|1] = tag[rt]*(m>>1);
		tag[rt] = 0;
	}
	return 0;
}

int build(int l,int r,int rt){
	if(l == r){
		sumn[rt] = 1;
		return 0;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushUp(rt);
	return 0;
}

int update(int p,int L,int R,int l,int r,int rt){
	if(L<=l && r<=R){
		tag[rt] = p;
		sumn[rt] = p*(r-l+1);
		return 0;
	}
	pushDown(rt,r-l+1);
	int m = (l+r)>>1;
	if(L<=m)update(p,L,R,lson);
	if(R>m)update(p,L,R,rson);
	pushUp(rt);
	return 0;
}

int main(){
	int T;
	scanf("%d",&T);
	For(i,1,T){
		int n,q;
		scanf("%d%d",&n,&q);
		build(1,n,1);
		memset(tag,0,sizeof(tag));
		int a,b,t;
		rep(j,q){
			scanf("%d%d%d",&a,&b,&t);
			update(t,a,b,1,n,1);
		}
		printf("Case %d: The total value of the hook is %d.\n",i,sumn[1]);
	}

    return 0;
}
