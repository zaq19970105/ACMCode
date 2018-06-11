using namespace std;
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>
#include <algorithm>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)

#define LOWBIT(x) ((x)&(-x))

//HUD 1394
//比线段树3快
const int maxn = 5005;
int treeArr[maxn],arr[maxn];

//树状数组单点更新
int add(int a,int b,int c){
	for(int i = a;i <= c;i += LOWBIT(i)){
		treeArr[i] += b;
	}
	return 0;
}

//树状数组区间求和
int getSum(int a,int b){
	int ans = 0;
	for(int i = b;i > 0;i -= LOWBIT(i)){
		ans += treeArr[i];
	}
	for(int i = a-1;i > 0;i -= LOWBIT(i)){
		ans -= treeArr[i];
	}
	return ans;
}

int main(){
	int n,ans,sumn;
	while(~scanf("%d",&n)){
		ans = 0;
		sumn = 0;
		memset(treeArr,0,sizeof(treeArr));
		memset(arr,0,sizeof(arr));
		For(i,1,n){
			scanf("%d",arr+i);
			++arr[i];
			sumn += getSum(arr[i],n);
			add(arr[i],1,n);
		}
		ans = sumn;
		For(i,1,n-1){
			sumn += n-(arr[i]<<1)+1;
			ans = min(ans,sumn);
		}
		printf("%d\n",ans);

	}
    return 0;
}
