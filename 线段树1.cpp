using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)

const int maxn = 1<<16;
int sumn[maxn<<2];

//HUD 1166
/*
	maxn是题目给的最大区间,而节点数要开4倍,确切的来说节点数要开大于maxn的最小
	2
	x
	的两倍
	 lson和rson分辨表示结点的左儿子和右儿子,由于每次传参数的时候都固定是这几个变量,
	所以可以用预定于比较方便的表示
	 以前的写法是另外开两个个数组记录每个结点所表示的区间,其实这个区间不必保存,一边
	算一边传下去就行,只需要写函数的时候多两个参数,结合lson和rson的预定义可以很方
	便
	PushUP(int rt)是把当前结点的信息更新到父结点
	PushDown(int rt)是把当前结点的信息更新给儿子结点
	rt表示当前子树的根(root),也就是当前所在的结
*/

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

//把当前节点信息更新到父节点
int pushUp(int rt){
    return sumn[rt] = sumn[rt<<1] + sumn[rt<<1|1];
}

//把当前节点信息更新到子节点
int pushDown(int rt){
	return 0;
}

//建立线段树
int build(int l,int r,int rt){
	if(l == r)return scanf("%d",sumn+rt);
	int m = (l+r)>>1;
	build(lson);
	build(rson);
	return pushUp(rt);
}

//更新线段树
//区间号p发生add变化
int update(int p,int add,int l,int r,int rt){
	if(l == r)return sumn[rt] += add;
	int m = (l+r)>>1;
	if(p<=m)update(p,add,lson);
	else update(p,add,rson);
	return pushUp(rt);
}

//求区间值[L,R]
int query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R)return sumn[rt];//妙不可言
	int m = (l+r)>>1,ans = 0;
	if(L<=m)ans += query(L,R,lson);
	if(R>m)ans += query(L,R,rson);
	return ans;
}

int main(){
    int T,N;
    char t[7];
	scanf("%d",&T);
    rep(i,T){
		scanf("%d",&N);
		printf("Case %d:\n",i+1);
		build(1,N,1);
		while(1){
			scanf("%s",t);
			if(*t == 'E')break;
			int a,b;
			scanf("%d%d",&a,&b);
			if(*t == 'Q')printf("%d\n",query(a,b,1,N,1));
			if(*t == 'A')update(a,b,1,N,1);
			if(*t == 'S')update(a,-b,1,N,1);
		}
    }
    return 0;
}
