#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	//getchar();
//	char b[81];
//	fgets(b, sizeof(b), stdin);//well,��׼�����һ��enterֱ��pass,,,������˭�ģ�����
//	printf("%s", b);
//}
int main()
{
	int i = 0;
	scanf("%d", &i);//��3 China�� ��� china,�ָ����Ǹ��ո�Ҳ�����ˡ�����
	getchar();//���ף�����getchar���գ�ֱ��pass��stdin.......��˵����stdinȷʵ����'\n'Ϊ������־�ģ������ڡ����ա�֮��Ÿ�֪���ġ�����������
	char b[81];
	if (i)fgets(b, sizeof(b), stdin);//������ǿ���ˡ��ֲ����У����ǣ�
	printf("%s", b);
}