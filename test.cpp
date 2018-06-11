#pragma comment(linker, "/STACK:1024000000,1024000000") //手动扩栈  
using namespace std;


#include <iostream> 　　　//数据流输入／输出 
#include <sstream>　　　　 //基于字符串的流 
#include <string>　　　　　//字符串类 
#include <fstream> 　　　 //文件输入／输出 
#include <complex>　　　　 //复数类 

#include <algorithm>　　　 //STL 通用算法
/*next_permutation(a,a+3)和prev_permutation() */
#include <map>　　　　　　 //STL 映射容器 
#include <queue>　　　　　 //STL 队列容器 
#include <set>　　　　　　 //STL 集合容器 
#include <vector>　　　　　//STL 动态数组容器 
#include <deque>　　　　　 //STL 双端队列容器 
#include <list>　　　　　　//STL 线性列表容器 
#include <iterator>        //STL 迭代器 
#include <stack>　　　　　 //STL 堆栈容器 
#include <bitset>　　　　　//STL 位集容器 
#include <numeric>         //STL常用的数字操作 
#include <memory>          //STL通过分配器进行的内存分配 
#include <functional>　　　//STL 定义运算函数（代替运算符）
#include <utility>　　　　 //STL 通用模板类 

#include <regex>
#include <cstdio> 　　　　 //定义输入／输出函数 
#include <cstdlib> 　　　　//定义杂项函数及内存分配函数 
#include <cctype>          //字符处理 
#include <cstring> 　　　　//字符串处理 
#include <cmath> 　　　　　//定义数学函数 
#include <ctime> 　　　　　//定义关于时间的函数 
#include <climits> 　　　　//定义各种数据类型最值的常量 
#include <clocale> 　　　　//定义本地化函数 
#include <csignal>         //信号机制支持 
#include <csetjmp>         //异常处理支持 
#include <cstdarg>         //不定参数列表支持 
#include <cwchar> 　　　　 //宽字符处理及输入／输出 
#include <cwctype> 　　　　//宽字符分类 
#include <cstddef>         //常用常量 
#include <cfloat>　　　　  //浮点数处理 
#include <cerrno> 　　　　 //定义错误码 
#include <ciso646>         //对应各种运算符的宏 

#include <exception>　　　 //异常处理类 
#include <limits> 　　　　 //定义各种数据类型最值常量 
#include <locale>          //本地化特定信息 
#include <new>             //动态内存分配 
#include <iomanip> 　　　  //参数化输入／输出 
#include <iOS>　　　　　　 //基本输入／输出支持 
#include <iosfwd>　　　　　//输入／输出系统使用的前置声明 
#include <stdexcept>　　　 //标准异常类 
#include <streambuf>　　　 //底层输入／输出支持 
#include <typeinfo>        //运行期间类型信息 
#include <valarray>        //对包含值的数组的操作 

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

#define   __max(a,b)   (((a)   >   (b))   ?   (a)   :   (b))
#define   __min(a,b)   (((a)   <   (b))   ?   (a)   :   (b))

#define msI(a) memset(a,inf,sizeof(a))
#define mss(a) memset(a,-1,sizeof(a))
#define ms1(a) memset(a,1,sizeof(a))
#define ms0(a) memset(a,0,sizeof(a))

#define Shell(n,gap,i,j,comp,swap,array) \
	for(int gap=n/2;gap>0;gap/=2) \
		for(int i=gap;i<n;i++) \
			for(int j=i-gap;j>=0&&comp(array[j],array[j+gap]);j-=gap) \
				swap(array[j],array[j+gap])


typedef vector<int> Vi;
typedef vector<string> Vs;
typedef map<int, int> Mii;
typedef map<string, int> Msi;
typedef map<int, string> Mis;
typedef map<string, string> Mss;
typedef pair<int, int> Pii;
typedef pair<string, int> Psi;
typedef pair<int, string> Pis;
typedef pair<string, string> Pss;
typedef long long LL;
typedef unsigned long long uLL;

const double PI = acos(0)*2;
const int inf = 0x3f3f3f3f;           //超过就算无穷大 
const LL infLL = 0x3f3f3f3f3f3f3f3fLL;

const int mod = 1000000007;

//快速幂
LL pow(LL x,LL y){
	LL base = x;
	LL ans = 1;

	while(y){
		if(y&1){
			ans *= base;
		}
		base *= base;
		y>>=1;
	}
	return ans;
}

//膜取快速幂
LL pow_mod(LL x,LL y){
	LL base = x;
	LL ans = 1;

	while(y){
		if(y&1){
			ans = (ans%mod * base) % mod;
		}
		base *= base;
		base %= mod;
		y>>=1;
	}
	return ans;
}

//bitset比大小
int bitsetComp(bitset<128> &a, bitset<128> &b)
{
    string stra = a.to_string();
    string strb = b.to_string();
    return (stra>strb?1:(stra<strb?-1:0));
}

//KMP模式串匹配
int KMP_next(const char* T,	int* next){
	int i = 0,j = 0;
	next[0] = 0;
	while(i < strlen(T)){
		if(0 == j || T[i] == T[j - 1]){
			++i,++j;
			T[i] != T[j - 1]?next[i] = j:next[i] = next[j - 1];
		}
		else j = next[j - 1];
	}
	return 0;
}

int KMP(const char* S,const char* T,int &pos,int &times){
	int next[strlen(T)],i = 0,j = 0;
	pos = inf;
	times = 0;
	KMP_next(T,next);

	while(i <= strlen(S)){
		if(0 == j || S[i - 1] == T[j - 1]){
			++i,++j;
		}
		else j = next[j - 1];
		if(j > strlen(T)){
			j = 1;
			if((S[i - 1] == ' ' || i - 1 == strlen(S)) && (S[i - strlen(T) - 2] == ' ' || i - 1 == strlen(T))){//找单词
				++times;
				pos = pos > i - strlen(T) - 1?i - strlen(T) - 1:pos;
			}
		}
	}
	return 0;
}

//阶乘膜
LL fact_mod(LL x){
	LL ans = 1;
	if(x)For(i,1,x)ans = (ans * (i % mod)) % mod;
	return ans;
}

//组合膜
LL comb_mod(LL m,LL n){
	LL ans = 1,a1 = 1,a2 = 1;

	if(m>n-m)m = n-m;

	For(i,1,m){
		a2 = (a2 * (i % mod)) % mod;
		a1 = (a1 * ((n-i+1) % mod)) % mod;
	}
	ans = (a1 * pow_mod(a2,mod - 2)) % mod;

	return ans;
}

#define LOWBIT(x) ((x)&(-x))
//比如100100110，取10,10000001，取1，取最后一个1到末尾  

//最大公约数与最小公倍数
LL gcd(LL x,LL y){
	LL t;
	while(y){
		t=x%y;
		x=y;
		y=t;
	}
	return x;
}

LL lcm(LL x,LL y){
	return x/gcd(x,y)*y;
}

//m个相同的元素和n个不同的元素的圆排列的种数为（m+n-1）！/(m!)种； 


int main()
{
	int t,e,f,n,p[501],w[501];//n物品种类,p价值,w权重   
	scanf("%d",&t);
	++t;
	while(--t){
		int W;
		scanf("%d %d %d",&e,&f,&n);
		W=f-e;//背包容量  
		For(i,1,n){
			scanf("%d %d",p+i,w+i);
		}
		
		int b[10001];
		memset(b,inf,sizeof(b));
		b[0]=0;
		
		For(i,1,n){//n件物品  
			For(j,w[i],W){
				if(b[j]>b[j-w[i]]+p[i]){
					b[j]=b[j-w[i]]+p[i];
				}
			}
		}
		
		if(b[W]!=inf){
			printf("The minimum amount of money in the piggy-bank is %d.\n",b[W]);
		}
		else{
			printf("This is impossible.\n");
		}
		
	}
    return 0;
}

