#include <iostream>         //数据流输入／输出
#include <sstream>          //基于字符串的流
#include <string>           //字符串类
#include <fstream>          //文件输入／输出
#include <complex>          //复数类

/*next_permutation(a,a+3)和prev_permutation() */
#include <algorithm>        //STL 通用算法
#include <map>              //STL 映射容器
#include <queue>            //STL 队列容器
#include <set>              //STL 集合容器
#include <vector>           //STL 动态数组容器
#include <deque>            //STL 双端队列容器
#include <list>             //STL 线性列表容器
#include <iterator>         //STL 迭代器
#include <stack>            //STL 堆栈容器
#include <bitset>           //STL 位集容器
#include <numeric>          //STL常用的数字操作
#include <memory>           //STL通过分配器进行的内存分配
#include <functional>       //STL 定义运算函数（代替运算符）
#include <utility>          //STL 通用模板类

#include <regex>            //正则表达式
#include <cstdio>           //定义输入／输出函数
#include <cstdlib>          //定义杂项函数及内存分配函数
#include <cctype>           //字符处理
#include <cstring>          //字符串处理
#include <cmath>            //定义数学函数
#include <ctime>            //定义关于时间的函数
#include <climits>          //定义各种数据类型最值的常量
#include <clocale>          //定义本地化函数
#include <csignal>          //信号机制支持
#include <csetjmp>          //异常处理支持
#include <cstdarg>          //不定参数列表支持
#include <cwchar>           //宽字符处理及输入／输出
#include <cwctype>          //宽字符分类
#include <cstddef>          //常用常量
#include <cfloat>           //浮点数处理
#include <cerrno>           //定义错误码
#include <ciso646>          //对应各种运算符的宏

#include <exception>        //异常处理类
#include <limits>           //定义各种数据类型最值常量
#include <locale>           //本地化特定信息
#include <new>              //动态内存分配
#include <iomanip>          //参数化输入／输出
#include <iOS>              //基本输入／输出支持
#include <iosfwd>           //输入／输出系统使用的前置声明
#include <stdexcept>        //标准异常类
#include <streambuf>        //底层输入／输出支持
#include <typeinfo>         //运行期间类型信息
#include <valarray>         //对包含值的数组的操作
using namespace std;

// copy from <stdint.h>
typedef signed char         int8;
typedef short               int16;
typedef long                int32;
typedef long long           int64;
typedef unsigned char       uint8;
typedef unsigned short      uint16;
typedef unsigned long        uint32;
typedef unsigned long long  uint64;
typedef float               float32;
typedef double              float64;

int score;
char str[110000 + 5];
int len;

/// @brief Manacher函数专用，求半径
/// @param diameter_len
/// @return
inline uint32 GetRadiusLen(uint32 diameter_len) {
    return diameter_len >> 1;
}

/// @brief 返回最长回文子串长度,复杂度O(n)
/// @param raw_str 原始字符串
/// @param raw_str_len 原始字符串长度
/// @return
uint32 Manacher(char raw_str[], uint32 raw_str_len) {
    uint32 max_len = 0;

    // 转换：abab => (#a#b#a#b#); aaa => (#a#a#a#)
    // 不转换的话只能处理奇数长度
    uint32 new_str_len = raw_str_len * 2 + 3;
    char* new_str = new char[new_str_len];
    // diameter_len[i]存以第i个字符为中心的回文子串长度
    uint32* diameter_len = new uint32[new_str_len];

    new_str[0] = '(';   // 回文左边界
    new_str[1] = '#';
    for (uint32 i = 0, j = 2; i < raw_str_len; ++i, j += 2) {
        new_str[j] = raw_str[i];
        new_str[j + 1] = '#';
    }
    new_str[new_str_len - 1] = ')'; // 回文右边界

    // 初始化
    for (uint32 i = 0; i < new_str_len; i++)
    {
        diameter_len[i] = 1;
    }

    for (uint32 i = 1, k = 0; i + k < new_str_len; i += k) {
        // k代表以i为中心的偏移
        k = 1;  // 设定最低偏移量
        // 计算以第i个字符为中心的回文子串长度
        while (true)
        {
            uint32 radius_len = GetRadiusLen(diameter_len[i]);

            // 越上界
            if ((i + (radius_len + 1)) >= new_str_len) {
                break;
            }
            // 越下界
            if ((int32)(i - (radius_len + 1)) < 0) {
                break;
            }
            // 两边字符相等,回文串长度加2,否则跳出
            if (new_str[i + (radius_len + 1)] == new_str[i - (radius_len + 1)])
            {
                diameter_len[i] += 2;
            }
            else
            {
                break;
            }
        }
        if (diameter_len[i] == 1)
        {
            continue;
        }

        // Manacher算法核心，以第i个字符为中心操作
        // 利用已知的diameter_len[i - k]计算diameter_len[i + k]
        for (uint32 j = i - 1; j >= i - GetRadiusLen(diameter_len[i]); --j) {
            k = i - j;
            if (i + k >= new_str_len)
            {
                break;
            }

            if (GetRadiusLen(diameter_len[i]) - k < GetRadiusLen(diameter_len[i - k])) {
                if (j == i - GetRadiusLen(diameter_len[i])) {
                    // 如果已经到达边界，那么从i+1~i+k的最优解肯定全部算出来了，直接跳到i+k+1继续算
                    ++k;
                    break;
                }
                // 这个条件下计算出来的diameter_len[i + k]是最优解，可以用反证法证明
                diameter_len[i + k] = diameter_len[i] - (k << 1);
            }
            else if (GetRadiusLen(diameter_len[i]) - k > GetRadiusLen(diameter_len[i - k])) {
                // 这个条件下计算出来的diameter_len[i + k]是最优解
                diameter_len[i + k] = diameter_len[i - k];
            }
            else {
                // 这个条件下计算出来的diameter_len[i + k]并非最优解，所以要跳出，用while循环来算最优diameter_len[i + k]
                diameter_len[i + k] = diameter_len[i - k];
                break;
            }
        }
    }

    // 取最大长度
    for (uint32 i = 0; i < new_str_len; i++)
    {
        max_len = max(max_len, diameter_len[i]);
    }

    delete[] diameter_len;
    delete[] new_str;

    return max_len >> 1;
}

int main() {
    while (cin >> str) {
        len = strlen(str);
        if (len <= 0) {
            continue;
        }

        score = Manacher(str, len);

        cout << score << endl;
    }
    return 0;
}