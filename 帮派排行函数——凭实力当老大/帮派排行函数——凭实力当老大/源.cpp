#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//内含随机值生成函数
#define N 9
#define M 15
int main()
{
	int gang[N][M];//九个帮派
	int boss[N];
	int* power;
	int i, j, k, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			gang[i][j] = rand() % 200;
	for (i = 0; i < N; i++)//帮派头目，凭实力夺取
	{
		for (k = 0, j = 1; j < M; j++)
			if (gang[i][k] < gang[i][j])
				k = j;
		boss[i] = gang[i][k];
	}
	printf("恶人武力值(power)一览：\n");
	for (i = 0; i < N; i++)
	{
		printf("帮会%d:\n", i + 1);
		printf("\40\40\40\40\40");
		for (j = 0; j < M; j++)
		{
			printf("%-5d", gang[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; i++)
		printf("%d ", boss[i]);
	printf("九大恶贼实力排行：\n");
	for (i = 0; i < N; i++)//选择法1不排序直接顺序输出，必出纰漏！
	{
		for (k = i, j = i + 1; j < N; j++)
			if (boss[k] < boss[j])
				k = j;
		temp = boss[k]; boss[k] = boss[i]; boss[i] = temp;
	}
	for (i = 0; i < N; i++)
		printf("第%d恶贼：\n%7d\n", i + 1, boss[i]);
	return 0;
}
