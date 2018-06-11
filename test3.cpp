using namespace std;

#include <cstdio>
#include <cstdlib>
#include <string>
#include <cstring>
#include <cmath>
#include <algorithm>
#include <iostream>

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

#define ms0(a) memset(a,0,sizeof(a))

#define __max(a,b)   (((a)   >   (b))   ?   (a)   :   (b))

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

const int maxn = 1000;

int tree[maxn];//以编号为值的树

int build(int n){
	int temp[maxn],left,right;//以编号为序号，编号在tree中实际序号为值的树
	ms0(temp);
	temp[1] = 1;
	For(i,1,n){
		cin>>left>>right;
		tree[temp[i]<<1] = left;
		tree[temp[i]<<1|1] = right;
		if(left)temp[left] = temp[i]<<1;
		if(right)temp[right] = temp[i]<<1|1;
	}
	return 0;
}

int getWidth(int depth){
	int width = 1,t;
	if(depth == 0)return 0;
	rFor(i,depth-1,(int)log2(width)+1){
		t = 0;
		rep(j,1<<i)if(tree[1<<i|j])++t;
		width = __max(width,t);
	}
	return width;
}

int getDepth(int rt){
	if(tree[rt] == 0)return 0;
	int LD = getDepth(rt<<1),RD = getDepth(rt<<1|1);
	if(LD != 0 && RD != 0) return 1+__max(LD,RD);
	return 1+LD+RD;
}

int main() {
	int n,depth;

	cin>>n;
	ms0(tree);
	tree[1] = 1;

	build(n);

	depth = getDepth(1);
	cout<<getWidth(depth)<<" "<<depth;

	return 0;
}

