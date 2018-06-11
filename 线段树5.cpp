using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

//POJ 2828

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn = 222222;
int sumn[maxn<<2];

int n;

int pushUp(int rt){
	return sumn[rt] = sumn[rt<<1] + sumn[rt<<1|1];
}

int build(int l,int r,int rt){
	if(l == r)return sumn[rt] = 1;
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	return pushUp(rt);
}

int query(int p,int l,int r,int rt){
	if(l == r)return r;
	int m = (l+r)>>1;
	if(p<=sumn[rt<<1])return query(p,lson);
	else return query(p - sumn[rt<<1],rson);
}

int update(int p,int l,int r,int rt){
	if(l == r)return sumn[rt] = 0;
	int m = (l+r)>>1;
	if(p<=m)update(p,lson);
	else update(p,rson);
	return pushUp(rt);
}

int main(){
	while(~scanf("%d",&n)){
		int t1[n+1],t2[n+1],t3[n+1];
		For(i,1,n){
			scanf("%d%d",t1+i,t2+i);
		}
		build(1,n,1);
		int ans;
		rFor(i,n,1){
			ans = query(t1[i]+1,1,n,1);
			//cout<<endl<<ans<<endl;
			update(ans,1,n,1);
			//cout<<endl<<sumn[1]<<" "<<sumn[4]<<" "<<sumn[5]<<" "<<sumn[6]<<" "<<sumn[7]<<" "<<endl;
			t3[ans] = t2[i];
		}

		For(i,1,n){
			printf("%d ",t3[i]);
		}
		printf("\n");
	}
	
    return 0;
}
