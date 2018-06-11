using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

//POJ 2886

#define lson l,m,rt<<1
#define rson m+1,r,rt<<1|1

const int rPrime[] = {1,2,4,6,12,24,36,48,60,120,180,240,360,720,840,1260,1680,2520,
					5040,7560,10080,15120,20160,25200,27720,45360,50400,55440,83160,
					110880,166320,221760,277200,332640,498960};

const int rFact[] = {1,2,3,4,6,8,9,10,12,16,18,20,24,30,32,36,40,48,60,64,72,80,84,
					90,96,100,108,120,128,144,160,168,180,192,200};

const int maxn = 555555;
int sumn[maxn<<2];

char names[500005][12];
int values[500005];

int pushUp(int rt){
	sumn[rt] = sumn[rt<<1] + sumn[rt<<1|1];
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

int update(int p,int l,int r,int rt){
	if(l == r){
		sumn[rt] = 0;
		return r;
	}
	int m = (l+r)>>1,ans = 0;
	if(p<=sumn[rt<<1])ans = update(p,lson);
	else ans = update(p-sumn[rt<<1],rson);
	pushUp(rt);
	return ans;
}

int main(){
	int n,k;
	while(~scanf("%d%d",&n,&k)){
		int p = 0;
		rep(i,sizeof(rPrime)/sizeof(rPrime[0])){
			if(n>=rPrime[i])p = i;
		}
		memset(values,0,sizeof(values));
		memset(names,0,sizeof(names));
		For(i,1,n){
			scanf("%s%d",names+i,values+i);
		}
		build(1,n,1);
		int out,mod;
		For(i,1,rPrime[p]-1){//out表示第i个要出列的人的原序号，k示第i个要出列的人的现序号
			out = update(k,1,n,1);
			mod = sumn[1];
			if(values[out]>0)k = ((k+values[out]-2)%mod+mod)%mod+1;
			else k = ((k+values[out]-1)%mod+mod)%mod+1;
		}

		printf("%s %d",names[update(k,1,n,1)],rFact[p]);
		
	}

    return 0;
}
