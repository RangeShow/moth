#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
//int main()
//{
//	int i;
//	scanf("%d", &i);
//	//getchar();
//	char b[81];
//	fgets(b, sizeof(b), stdin);//well,标准输出流一个enter直接pass,,,不管是谁的，，，
//	printf("%s", b);
//}
int main()
{
	int i = 0;
	scanf("%d", &i);//打3 China， 输出 china,分隔的那个空格也吸收了。。。
	getchar();//离谱，不加getchar吸收，直接pass了stdin.......这说明了stdin确实是以'\n'为结束标志的，且是在“吸收”之后才感知到的。。。。。。
	char b[81];
	if (i)fgets(b, sizeof(b), stdin);//这样勉强有了“分步”感，但是，
	printf("%s", b);
}