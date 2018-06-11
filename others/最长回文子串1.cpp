using namespace std;

#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <string>
#include <cstring>
#include <cmath>
#include <cctype>
#include <algorithm>

typedef long long LL;

#define rep(i,n) for (int i = 0; i < (n); ++i)
#define For(i,s,t) for (int i = (s); i <= (t); ++i)
#define rFor(i,t,s) for (int i = (t); i >= (s); --i)

#define ms0(a) memset(a,0,sizeof(a))

#define   __max(a,b)   (((a)   >   (b))   ?   (a)   :   (b))
#define   __min(a,b)   (((a)   <   (b))   ?   (a)   :   (b))

int delSame(char s[]){
	char x[105];
	int flag = 1,length = 0;
	rep(i,strlen(s)){
		if(s[i] == s[i+1])flag = 0;
		else flag?x[length++] = s[i]:flag = 1;
	}
	x[length] = '\0';
	if(length != strlen(s)){
		strcpy(s,x);
		delSame(s);
	}
	return 0;
}

/*
//返回最长回文子串长度
int Manacher(char s[]){
	//dia[i]存以第i个字符为中心的回文子串长度
	int rad[105],maxn = 0,length = strlen(s);
	if(length == 0)return 0;
	rep(i,length)rad[i] = 0;
	
	for(int i = 1,j = 0,k;i < length;i += k){
		//k代表偏移
		//算以第i个字符为中心的回文子串长度
		while (s[i-j-1] && s[i+j+1] && s[i-j-1] == s[i+j+1]) ++j;
        rad[i] = j;

		//以第i个字符为中心操作
		for (k = 1; k <= rad[i] && rad[i-k] != rad[i]-k; ++k) { // 利用类似镜像的方法缩短了时间
            rad[i+k] = __min(rad[i-k], rad[i]-k);
        }
        j = __max(j-k, 0);
		
	}
	
	rep(i,length)maxn = __max(maxn,rad[i]);
	return maxn<<1|1;
}
*/

int main() {
	int n,score;
	char str[105],temp[105];
	int maxS;
	cin>>n;
	rep(i,n){
		maxS = 0;
		cin>>str;
		rFor(j,strlen(str),1){
			rep(k,3){
				strcpy(temp,str);
				temp[j] = 'A'+k;
				temp[j+1] = '\0';
				strcat(temp,str+j);

				score = strlen(temp);
				delSame(temp);
				score -= strlen(temp);
				maxS = __max(maxS,score);
			}
		}
		cout<<maxS<<endl;
	}
	return 0;
}
