#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
int main()//�������ʵĺ�������Ȼ�С����롱��Ҫ�ų�
{
	void print_longest(char(*p)[81], int n);
	char a[81][81] = { 0 };
	char c = 0;
	int i = 0;
	printf("���ڴ��һ���ո����������ַ�����\n"); //printf(" ");// �Լ���Ŀո������
	while ((c = getchar()) != '\n')//getcharֻ���̵��ˡ���һ���ַ�(��ʼ����Ҳû��)������ո񡰴��͡�
		scanf("%s", a[i++]);
	i = 0;
	while (*a[i] != '\0')
		//printf("%s\n", a[i++]);
		i++;
	print_longest(a, i);//i Ϊ���������±꣬����a[i]װ����'\n'����������,i����Ϊ����
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
			if (isword)//�����ˣ����ĩβֻ����ĸ����ôд�Ի������!!!
				if ((*(*(p + i) + j) >= 'A' && *(*(p + i) + j) <= 'Z') || (*(*(p + i) + j) >= 'a' && *(*(p + i) + j) <= 'z'))
					num[i]++;
				else
				{
					isword = 0;
					num[i] = 0;//����������
					//break;//����break��ˬ��������
				}
			//num[i] = 0;������ôд��Ҳ�м�������ĸ����������ĸ��������ʹ֮��Ϊ���ķ���
		}
	}
	for (j = 1, k = 0; j <= n - 1; j++)
	{
		if (num[k] < num[j])//һֱ��jд��i��ϰ������£�����!!!!
			k = j;
	}
	for (i = 0; i < n; i++)//�������
		printf("%d\n", num[i]);
	printf("%s", p[k]);
}