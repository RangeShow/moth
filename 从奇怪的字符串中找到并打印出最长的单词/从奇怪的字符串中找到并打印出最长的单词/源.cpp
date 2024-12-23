#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()//打出最长单词的函数，自然有“乱码”需要排除
{
	void print_longest(char(*p)[81], int n);
	char a[81][81] = { 0 };
	char c = 0;
	int i = 0;
	printf("请在打出一个空格后输出您的字符串：\n"); //printf(" ");// 自己打的空格不能替代
	while ((c = getchar()) != '\n')//getchar只“吞掉了”第一个字符(初始化从也没用)——打空格“代餐”
		scanf("%s", a[i++]);
	i = 0;
	while (*a[i] != '\0')
		//printf("%s\n", a[i++]);
		i++;
	print_longest(a, i);//i 为有内容物下标，不过a[i]装的是'\n'，舍弃掉吧,i就作为行数
	return 0;
}
void print_longest(char(*p)[81], int n)
{
	int i, j, num[81] = { 0 };
	int isword = 1;
	int k = 0;
	for (i = 0; i < n; i++)
	{
		isword = 1;
		for (j = 0; *(*(p + i) + j) != '\0'; j++)
		{
			if (isword)//明白了，如果末尾只有字母，这么写仍会计数啊!!!
				if ((*(*(p + i) + j) >= 'A' && *(*(p + i) + j) <= 'Z') || (*(*(p + i) + j) >= 'a' && *(*(p + i) + j) <= 'z'))
					num[i]++;
				else
				{
					isword = 0;
					num[i] = 0;//别忘了清零
					//break;//还是break豪爽啊啊啊啊
				}
			//num[i] = 0;仅仅这么写，也有计量非字母后面所有字母数量，并使之成为最大的风险
		}
	}
	for (j = 1, k = 0; j <= n - 1; j++)
	{
		if (num[k] < num[j])//一直把j写成i，习惯真可怕！！！!!!!
			k = j;
	}
	for (i = 0; i < n; i++)//调试语句
		printf("%d\n", num[i]);
	printf("%s", p[k]);
}