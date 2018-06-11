using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

//HUD 1754

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

int maxn[1<<20];

int pushUp(int rt){
	return maxn[rt] = max(maxn[rt<<1],maxn[rt<<1|1]);
}

int build(int l,int r,int rt){
	if(l == r)return scanf("%d",maxn+rt);
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	return pushUp(rt);
}

int query(int L,int R,int l,int r,int rt){
	if(L<=l && r<=R)return maxn[rt];
	int m = (l+r)>>1,ans = 0;
	if(L<=m)ans = max(query(L,R,lson),ans);
	if(R>m)ans = max(query(L,R,rson),ans);
	return ans;
}

int update(int p,int sc,int l,int r,int rt){
	if(l == r)return maxn[rt] = sc;
	int m = (l+r)>>1;
	if(p<=m)update(p,sc,lson);
	else update(p,sc,rson);
	return pushUp(rt);
}

int main(){
    int N,M;
    char t[2];
    while(~scanf("%d%d",&N,&M)){
    	build(1,N,1);
	    while(M--){
	    	scanf("%s",t);
	    	int a,b;
	    	scanf("%d%d",&a,&b);
	    	if(t[0] == 'Q')printf("%d\n",query(a,b,1,N,1));
	    	if(t[0] == 'U')update(a,b,1,N,1);
	    }
    }
    return 0;
}
