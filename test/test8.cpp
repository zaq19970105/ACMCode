using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>
#include <cassert>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define drep(i,j,n,m) for (int i = 0; i < (n); ++i) \
						for (int j = 0; j < (m); ++j)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

#define   __max(a,b)   (((a)   >   (b))   ?   (a)   :   (b))
#define   __min(a,b)   (((a)   <   (b))   ?   (a)   :   (b))

#define LOWBIT(x) ((x)&(-x))


#define ms0(a) memset(a,0,sizeof(a))
#define msI(a) memset(a,inf,sizeof(a))
#define mp(d,s) memcpy(d, s, sizeof(s))

typedef long long LL;
typedef pair<int, int> Pii;
typedef map<int, int> Mii;
typedef map<string, string> Mss;
typedef map<string, int> Msi;
typedef multimap<int, int> MMii;

const int inf = 0x3f3f3f3f;
const int maxN = 1000+5;
int Init();
int init();
int print();
int output();

LL OR(LL x,LL y){return (((x)&(~y)) ^ ((~x)&(y)));}

int minX,maxX,minY,maxY;
struct Point{
	int X,Y;
	Point(int x = 0,int y = 0):X(x),Y(y){}
	int setXY(int x,int y){return X = x,Y = y;}
	int print(){return printf("(%d,%d)",X,Y);}
	bool isLegal(){return X >= minX && X <= maxX && Y >= minX && Y <= maxX;}
};
Point operator+ (const Point& x, const Point& y){
	return Point(x.X+y.X,x.Y+y.Y);
}
Point operator* (const int& k, const Point& x){
	return Point(k*x.X,k*x.Y);
}

typedef Point Vector;
Vector vec[8] = {Vector(0,1),Vector(0,-1),Vector(-1,0),Vector(1,0),Vector(1,1),Vector(-1,-1),Vector(-1,1),Vector(1,-1)};

bool flag;
int seq = 0;
map< char, string > key;


int main(){
	//FILE* fp = fopen("data8.txt","r");
	//freopen("data8.txt","w",stdout);
	//Init();
	int t;
	while(init()){
		//print();
		
		output();
	}
	
	//close(fp);
	
    return 0;
}

int Init(){
	minX = 0;
	maxX = 7;
	minY = 0;
	maxY = 7;
	char t1[2],t2[7];
	rep(36){
		cin>>t1>>t2;
		key[t1[0]] = t2;
	}
	
	
	return 0;
}

int init(){
	
	return 1;
}

int print(){
	
	return 0;
}

int output(){
	
	return 0;
}



