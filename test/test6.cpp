using namespace std;
#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <cstring>
#include <string>
#include <cmath>
#include <algorithm>

#include <vector>

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)
#define foreach(i,c) for (__typeof(c.begin()) i = c.begin(); i != c.end(); ++i)

#define pr(x) cout << #x << " = " << x << "  "
#define prln(x) cout << #x << " = " << x << endl

#define   __max(a,b)   (((a)   >   (b))   ?   (a)   :   (b))
#define   __min(a,b)   (((a)   <   (b))   ?   (a)   :   (b))

#define msI(a) memset(a,inf,sizeof(a))

typedef long long LL;
typedef pair<int, int> Pii;

const int inf = 0x3f3f3f3f;

const int maxn = 1005;  

typedef int Matrix[maxn][maxn];  
int n,m;
int aux[100005];
int auxn;

Matrix e,A; 

int Rank(int up) { 
	
	For(i,1,n){
		For(j,1,n){
			if(e[i][j] <= up) A[i-1][j-1] = e[i][j];
			else A[i-1][j-1] = 0;
		}
	}
	
    int i = 0, j = 0, k, r, u;  
    while (i < n && j < n) { //第n列为矩阵右边的值  
        r = i; //选主行  
        for (k = i; k < n; ++k) {  
            if (A[k][j]) { //向下选，定主行  
                r = k;  
                break;  
            }  
        }  
        if (A[r][j]) {  
            if (r != i)//主行上移，i行才是真正的主子  
                for (k = 0; k <= n; ++k)  
                    swap(A[r][k], A[i][k]);  
            for (u = i + 1; u < n; ++u)  
                if (A[u][j])  
                    for (k = i; k <= n; ++k)  
                        A[u][k] ^= A[i][k];  
            ++i;  
        }  
        ++j;  
    }  
        
    return i;  
}  

int init(){
	int x,y,z;
	cin>>n>>m;

	For(i,1,m){
		cin>>x>>y>>z;
		++z;
		if(e[x][y] == 0)e[x][y] = z;
		else e[x][y] = __min(z,e[x][y]);
	}
	
	For(i,1,n){
		For(j,1,n){
			if(e[i][j])	aux[++auxn] = e[i][j];
		}
	}
	sort(aux+1,aux+auxn+1);
	
	int k = 0;
	int old = -1;
	
	For(i,1,auxn){
		if(old != aux[i]){
			aux[++k] = aux[i];
			old = aux[i];
		}
	}
	auxn = k;
	
	return 0;
}

int main(){
	init();
	
	int now = 2;
	int i = 2;
	int t;
	int old = 1;
	int up = Rank(aux[auxn]);
	
	cout << aux[1]-1;
	if(n != 1)cout<<" ";
	
	while(i <= n){
		if(now > up)break;
		else {
			t = Rank(aux[i]);
			if(old != t){
				cout<<aux[i]-1;
				if(now != n)cout<<" ";
				old = t;
				++now;
			}
			++i;	
		}
	}
	
	For(j,up+1,n){
		cout<<-1;
		if(j!=n)cout<<" ";
	}
	
    return 0;
}



