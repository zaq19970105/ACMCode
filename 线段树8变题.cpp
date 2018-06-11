using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

//POJ 3468

typedef long long LL;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 111111;
LL tree[maxn<<2];
LL tag[maxn<<2];

int pushUp(int rt){
	tree[rt] = tree[rt<<1] + tree[rt<<1|1];
	return 0;
}

int pushDown(int rt,int m){
	if(tag[rt]){
		tag[rt<<1] += tag[rt];
		tag[rt<<1|1] += tag[rt];
		tree[rt<<1] += (m-(m>>1))*tag[rt];
		tree[rt<<1|1] += (m>>1)*tag[rt];
		tag[rt] = 0;
	}
	return 0;
}

int build(int l,int r,int rt){
	tag[rt] = 0;
	if(l == r){
		scanf("%I64d",tree+rt);
		return 0;
	}
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	pushUp(rt);
	return 0;
}

LL query(int L,int R,int l,int r,int rt){
	if(L<=l && r<=R)return tree[rt];
	pushDown(rt,r-l+1);
	int m = (l+r)>>1;
	LL ans = 0;
	if(L<=m)ans += query(L,R,lson);
	if(R>m) ans += query(L,R,rson);
	return ans;
}

int update(int L,int R,int p,int l,int r,int rt){
	if(L<=l && r<=R){
		tag[rt] += p;
		tree[rt] += (LL)p*(r-l+1);
		return 0;
	}
	pushDown(rt,r-l+1);
	int m = (r+l)>>1;
	if(L<=m)update(L,R,p,lson);
	if(R>m)update(L,R,p,rson);
	pushUp(rt);
	return 0;
}

int n,q;
int a,b,c;
char t[2];

int main(){
	scanf("%d%d",&n,&q);
	build(1,n,1);
	rep(i,q){
		scanf("%s",t);
		if('C' == t[0]){
			scanf("%d%d%d",&a,&b,&c);
			update(a,b,c,1,n,1);
		}
		else {
			scanf("%d%d",&a,&b);
			printf("%I64d\n",query(a,b,1,n,1));
		}
	}
    return 0;
}
