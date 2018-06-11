using namespace std;
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <fstream>

#define rep(i,n) for (int i = 0; i < (n); ++i)

const int maxn = 1<<16;
int sumn[maxn<<2];

//建立线段树
int build(int l,int r,int rt){
	if(l == r){
		cin>>sumn[rt];
		return 0;
	}
	int m = (l+r)>>1;
	build(l,m,rt<<1);
	build(m+1,l,rt<<1|1);
	pushUp(rt);
	return 0;
}

//把当前节点信息更新到父节点
int pushUp(int rt){
    sumn[rt] = sumn[rt<<1] + sumn[rt<<1|1];
	return 0;
}

//把当前节点信息更新到子节点
int pushDown(int rt){
	return 0;
}

//更新线段树
int update(){
	
	return 0;
}

//求区间值[L,R]
int query(int L,int R,int l,int r,int rt){
	if(L <= l && r <= R){//妙不可言
		return sumn[rt];
	}
	int m = (l+r)>>1,ans = 0;
	if(L<=m){
		ans += query(L,R,l,m,rt<<1);
	}
	if(R>m){
		ans += query(L,R,m+1,r,rt<<1|1);
	}
	return ans;
}

int main(){
    int T,N;
    cin>>T;
    while(T--){
		cin>>N;
		build(1,N,1);
		
    }


    return 0;
}
