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

int n,score;
char str[105],len;

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

int rad(int dia){
	return dia>>1;
}

//返回最长回文子串长度
int Manacher(char s[]){
	//dia[i]存以第i个字符为中心的回文子串长度
	int dia[105],maxn = 0,length = strlen(s);
	rep(i,length)dia[i] = 1;
	
	for(int i = 1,k = 0;i+k < length;i += k){
		//k代表偏移
		//算以第i个字符为中心的回文子串长度
		for(k = 1;(1+i+rad(dia[i]))<length && (-1+i-rad(dia[i]))>=0 && s[1+i+rad(dia[i])] == s[-1+i-rad(dia[i])];dia[i] += 2);
		if(dia[i] == 1)continue;

		//以第i个字符为中心操作
		rFor(j,i-1,i-rad(dia[i])){
			k = i-j;
			if(i+k >= length)break;
			if(rad(dia[i])-k < rad(dia[i-k])){
				if(j == i-rad(dia[i])){
					++k;
					break;
				}
				dia[i+k] = dia[i]-k<<1;
			}
			else if(rad(dia[i])-k > rad(dia[i-k])){
				dia[i+k] = dia[i-k];
			}
			else {
				dia[i+k] = dia[i-k];
				break;
			}
		}
	}
	
	rep(i,length){
		maxn = __max(maxn,dia[i]);
		//cout<<s[i]<<":"<<dia[i]<<endl;
	}
	return maxn;
}

int main() {
	cin>>n;
	rep(i,n){
		score = 1;
		cin>>str;
		len = strlen(str);
		
		delSame(str);
		score += (len-strlen(str));
		
		score += Manacher(str);

		cout<<score<<endl;
	}
	
	
	
	
	return 0;
}



