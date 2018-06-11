using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

//HUD 2795

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 222222;
int _max[maxn<<2];

int h,w,n;

int pushUp(int rt){
	return _max[rt] = max(_max[rt<<1],_max[rt<<1|1]);
}

int update(int p,int l,int r,int rt){
	if(p>w-abs(_max[rt]))return -1;
	if(l == r){
		_max[rt] -= p;
		return r;
	}
	int m = (l+r)>>1,ans = 0;
	if(p<=w-abs(_max[rt<<1]))ans = update(p,lson);
	else ans = update(p,rson);
	pushUp(rt);
	return ans;
}

int main(){
	int t;
	while(~scanf("%d%d%d",&h,&w,&n)){
		if(h>n)h = n;
		memset(_max,0,sizeof(_max));
		rep(i,n){
			scanf("%d",&t);
			t = update(t,1,h,1);
			if(-1 != t)printf("%d\n",t);
			else printf("-1\n");
		}
	}
    return 0;
}
