#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#define N 54
#define C 19
int check(int score)
{
	switch (score / 10)
	{
	case 10:
	case 9:return 1; break;
	case 8:
		switch (score % 10)
		{
		case 9:
		case 8:
		case 7:
		case 6:
		case 5:return 1; break;
		default:break;
		}; break;
	default: break;
	}
	return 0;
}

int main()//计算班级的优秀率
{
	int clascore[C][N], i, j;
	float rate[C] = { 0.0 };
	for (i = 0; i < C; i++)
		for (j = 0; j < N; j++)
			clascore[i][j] = rand() % 101;//居然固定生成了？！
	for (i = 0; i < C; i++)
	{
		printf("class%d:", i + 1);
		for (j = 0; j < N; j++)
			printf("%-4d", clascore[i][j]);
		printf("\n");
	}
	for (i = 0; i < C; i++)
	{
		for (j = 0; j < N; j++)
			if (check(clascore[i][j]))
				rate[i]++;
		rate[i] /= N;
	}
	for (i = 0; i < C; i++)
		printf("%2d班的优秀率：%5.1f%%\n", i + 1, rate[i] * 100);
	return 0;
}