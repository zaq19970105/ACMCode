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

int n;
int a[100005];
int ans,cP;


int main(){
	cin>>n;
	int t;
	
	rep(i,n){
		cin>>a[i];
	}
	rep(i,n){
		cin>>t;
		a[i] -= t;
		ans += i * abs(a[i]);
	}
	
	rFor(i,n-1,0){
		if(a[i] > 0){
			cP += a[i];
		}
		else if(a[i] < 0){
			if(-a[i] > cP){
				ans -= cP * i;
				cP = 0;
			}
			else if(cP >= -a[i]){
				ans += a[i] * i;
				cP += a[i];
			}
		}
	}
	
	cout<<ans;
	
   
    return 0;
}


