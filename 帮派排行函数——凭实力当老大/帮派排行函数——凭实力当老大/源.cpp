#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>//�ں����ֵ���ɺ���
#define N 9
#define M 15
int main()
{
	int gang[N][M];//�Ÿ�����
	int boss[N];
	int* power;
	int i, j, k, temp;
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			gang[i][j] = rand() % 200;
	for (i = 0; i < N; i++)//����ͷĿ��ƾʵ����ȡ
	{
		for (k = 0, j = 1; j < M; j++)
			if (gang[i][k] < gang[i][j])
				k = j;
		boss[i] = gang[i][k];
	}
	printf("��������ֵ(power)һ����\n");
	for (i = 0; i < N; i++)
	{
		printf("���%d:\n", i + 1);
		printf("\40\40\40\40\40");
		for (j = 0; j < M; j++)
		{
			printf("%-5d", gang[i][j]);
		}
		printf("\n");
	}
	for (i = 0; i < N; i++)
		printf("%d ", boss[i]);
	printf("�Ŵ����ʵ�����У�\n");
	for (i = 0; i < N; i++)//ѡ��1������ֱ��˳��������س��©��
	{
		for (k = i, j = i + 1; j < N; j++)
			if (boss[k] < boss[j])
				k = j;
		temp = boss[k]; boss[k] = boss[i]; boss[i] = temp;
	}
	for (i = 0; i < N; i++)
		printf("��%d������\n%7d\n", i + 1, boss[i]);
	return 0;
}
