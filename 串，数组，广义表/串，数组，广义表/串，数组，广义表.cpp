#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

//串可以看成线性表--内容只能是字符
//数组，广义表可以看成线性表的推广
//严格来讲他们都不是线性结构

//串也叫字符串，是零个或多个字符构成的有限序列
//串长为零的串叫做空串，用空集的符号表示
//子串：一个串中任意个连续字符组成（含空串）的字序列
//真子串：不包含自己的子串
//子串的位置是子串第一个字符在主串的位置
//空格串：串的内容是空格。空格串和空串不是一回事

//串的线性存储结构
#define MAXLEN 255
typedef struct string
{
	char ch[MAXLEN + 1];//数组的第一个元素不放数据，使下标和元素统一
	int length;
}SString;
//串的链式存储结构--块链(存储密度大)
#define CHUNKSIZE 80
typedef struct Chuck
{
	char ch2[CHUNKSIZE];
	struct Chunk* next;
}Chunk;

typedef struct LString
{
	Chunk* head, * tail;
	int curlen;
}LString;

//查找子串
int Index_BF(SString S, SString T)//O（n*m）
{
	int i = 1, j = 1;
	while (i <= S.length && j <= T.length)
	{
		if (S.ch[i] == T.ch[j])
		{
			i++;
			j++;
		}
		else
		{
			i = i - j + 2;//数组第一个元素不放
			//i=i-j+1数组第一个元素放
			j = 1;
		}
	}
	if (j > T.length)
	{
		return i - T.length;//返回下标
	}
	else
		return -1;
}

//最前面的k个字符和j之前的最后k个字符是一样的。
//模式串中各个字符对应的 next 值的计算方式：
//取该字符前面的字符串（不包含自己），
//其前缀字符串和后缀字符串相同字符的个数再 +1 就是该字符对应的 next 值。
//就是找最大的前置字符串然后移动
//KMP算法  时间复杂度O（n+m）
void Next(char* T, int* next) {
    int j = 0;
    int i = 1;
    next[1] = 0;
    while (i < strlen(T)) {
        if (j == 0 || T[i - 1] == T[j - 1]) {
            i++;
            j++;
            next[i] = j;
        }
        else {
            j = next[j];
        }
    }
}
int KMP(char* S, char* T) {
    int next[10];
    int i = 1;
    int j = 1;
    Next(T, next);//根据模式串T,初始化next数组
    while (i <= strlen(S) && j <= strlen(T)) {
        //j==0:代表模式串的第一个字符就和当前测试的字符不相等；S[i-1]==T[j-1],如果对应位置字符相等，两种情况下，指向当前测试的两个指针下标i和j都向后移
        if (j == 0 || S[i - 1] == T[j - 1]) {
            i++;
            j++;
        }
        else {
            j = next[j];//如果测试的两个字符不相等，i不动，j变为当前测试字符串的next值
        }
    }
    if (j > strlen(T)) {//如果条件为真，说明匹配成功
        return i - (int)strlen(T);
    }
    return -1;
}
int main() {
    char ch1[] = "ababcabcacbab";
    char ch2[] = "abcac";
    int i = KMP(ch1,ch2);
    printf("%d", i);
    return 0;
}

//数组：相同数据类型的数据集合
//二维数组物理上是线性的，逻辑上可以是也可以不是
//以行序为主序 
//n是行数 m是一行有几个元素 j是列数 k是每个元素占的字节
//位置：LOC(0,0)+k*(n*m+j)


//三角矩阵--重复元素占一个元素空间，元素一共占n(n+1)/2+1
// 
//上三角矩阵
//k=(i-1)*(2n-i+2)/2-j+i+1 i<=j
//k=n(n+1)/2+1  i>j

//下三角矩阵
//k=i(i-1)/2+j  i>=j 
//k=n(n+1)/2+1  i<j

//稀疏矩阵存储方法：
//1.三元组法---（行，列，值）
//三元组线性表第一个元素放（数组行数，数组列数，多少个非零数据）
//2.十字链表

//广义表 --元素是原子
//表头：可以是第一个元素，也可以是一个字表
//head(LS)=a1;
//表尾：除了表头其他元素构成的表--注意是表
//tail(LS)=（a2,a3…an）
//广义表有相应的次序：直接前驱和直接后继
//广义表的深度：括号的重数
//广义表的长度：最表面的括号的元素个数
//注意：原子的深度是0，空表的深度是1
//广义表是可以递归的表
//递归的广义表长度是有限的，深度是无限的
//广义表是可以互相共享的--比如下面的表E
//广义表是多层次的结构，可以用图形一层层展开

//例子
//A=()表长为零，空表
//B=(())表长为1，不是空表，表头表尾都是()
//C=(a,(b,c))表长为2，表头为a，表尾是((b,c))
//D=(a,b,c)表长为3，表头为a，表尾是(b,c)
//E=(C,D)表长为2，表头为C，表尾是(D)
//F=(a,F)表长2,表头为a,表尾是(F)本身
