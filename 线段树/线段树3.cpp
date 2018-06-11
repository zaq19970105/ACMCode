using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

//HUD 1394
//此题比较难想到用线段树，其叶子结点为1表示这个数出现过，并在当前数前面，且比它大，0则表示还没出现过

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 5555;
int sumn[maxn<<2];

int pushUp(int rt){
	return sumn[rt] = sumn[rt<<1] + sumn[rt<<1|1];
}

int build(){
	memset(sumn,0,sizeof(sumn));
	return 0;
}

int query(int L,int R,int l,int r,int rt){
	if(L<=l && r<=R)return sumn[rt];
	int m = (l+r)>>1,ans = 0;
	if(L<=m)ans += query(L,R,lson);
	if(R>m)ans += query(L,R,rson);
	return ans;
}

int update(int p,int l,int r,int rt){
	if(l == r)return ++sumn[rt];
	int m = (l+r)>>1;
	if(p<=m)update(p,lson);
	else update(p,rson);
	return pushUp(rt);
}


int main(){
	int n,t[maxn],ans;
	while(~scanf("%d",&n)){
		build();
		ans = 0;
		rep(i,n){
			scanf("%d",t+i);
			ans += query(t[i],n-1,0,n-1,1);//比t[i]大且出现过的数目
			update(t[i],0,n-1,1);
		}
		
		t[maxn-1] = ans;
		rep(i,n-1){
			t[maxn-1] += n-(t[i]<<1)-1;
			ans = min(ans,t[maxn-1]);
		}
		printf("%d\n",ans);
		
	}
    return 0;
}
