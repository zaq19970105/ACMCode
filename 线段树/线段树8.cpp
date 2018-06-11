using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

//HDU 4267

typedef long long LL;

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int maxn 55555;
int tree[maxn<<2][55];
int tag[maxn<<2];
int id[11][10];//id[k][a%k]
int locate;

int pushDown(int rt){

	return 0;
}

int query(int p,int l,int r,int rt){
	if(l == r)return tree[rt];
	int m = (l+r)>>1,ans = 0;
	if(p<=m)ans = query(p,lson);
	else ans = query(p,rson);
	return ans;
}

int update(int L,int R,int p,int l,int r,int rt){
	
	return 0;
}

int main(){
	int n = 0,q;
	//以横坐标为余数，纵坐标为膜数定位线段树(一共55棵)
	For(i,1,10){
		For(j,0,i-1){
			id[i][j] = n++;
		}
	}
	while(~scanf("%d",&n)){
		memset(tree,0,sizeof(tree));
		memset(tag,0,sizeof(tag));
		scanf("%d",&q);
		int t;
		rep(i,q){
			scanf("%d",&t);
			if(1 == t){
				int a,b,k,c;
				scanf("%d%d%d%d",&a,&b,&k,&c);
				locate = id[k][a%k];
				update(a,b,c,1,n,1);
			}
			else {
				scanf("%d",&t);
				printf("%d\n",query(t,1,n,1));
			}
		}
	}
    return 0;
}
