using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <cmath>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

#define N 500000

//100以内的素数
const int prime[] = {2,3,5,7,11,13,17,19,23,29,31,37,41,43,47,53,59,61,67,71,73,79,83,89,97};

int rPrime[100],rPn = 0,rFact[100];

int powI(int base,int index){
	int ans = 1;
	for(;index;index >>= 1){
		if(index & 1){
			ans *= base;
		}
		base *= base;
	}
	return ans;
}

//获取一个数的约数个数
int getDivisors(int x){
	if(1 == x)return 1;
	int ans = 1,len = sizeof(prime)/sizeof(prime[0]);
	int pC[len];
	memset(pC,0,sizeof(pC));
	rep(i,len){
		if(1 == x)break;
		if(x%prime[i] == 0){
			int base = prime[i];//基数
			int index = (int)(log10(x)/log10(base))+1;//指数
			for(int j = powI(base,index);1 != j;j /= base,--index){
				if(0 == x%j){
					x /= j;
					pC[i] = index;
					break;
				}
			}
		}
	}
	rep(i,len){
		ans *= pC[i]+1;
	}
	return ans;
}

//求[1,N]的反素数
int getRPrime(){
	int maxNumofDivisor = 0;
	
	For(i,1,N){
		int t = getDivisors(i);
		if(t > maxNumofDivisor){
			maxNumofDivisor = t;
			rPrime[rPn] = i;
			rFact[rPn] = t;
			++rPn;
		}
	}
	
	return 0;
}

int main(){
	getRPrime();
	rep(i,rPn){
		cout<<rPrime[i];
		if(i != rPn-1)cout<<",";
	}
	cout<<endl;
	rep(i,rPn){
		cout<<rFact[i];
		if(i != rPn-1)cout<<",";
	}
	
	return 0;
}
