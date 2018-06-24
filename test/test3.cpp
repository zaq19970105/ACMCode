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
#include<cassert>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

#define   __max(a,b)   (((a)   >   (b))   ?   (a)   :   (b))
#define   __min(a,b)   (((a)   <   (b))   ?   (a)   :   (b))

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
const int maxN = 100+5;


bool flag;
int seq = 0;

int Init(){
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

int main(){
	//FILE* fp = fopen("data8.txt","r");
	//freopen("data3.txt","w",stdout);
	//Init();
	while(0){
		
		//output();
	}
	
	
MMii c1;   
  
    c1.insert(MMii::value_type('a', 1));   
    c1.insert(MMii::value_type('b', 2));   
    c1.insert(MMii::value_type('b', 2));   
    c1.insert(MMii::value_type('f', 3));   
    c1.insert(MMii::value_type('d', 4));   
  
    for (MMii::const_iterator it = c1.begin(); it != c1.end(); ++it)   
        std::cout << " [" << (char)it->first << ", " << it->second << "]";   
    std::cout << std::endl; 
	
	//close(fp);
	
    return 0;
}

