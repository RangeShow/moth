#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <math.h>
//int main()
//{
//	double a, b, c, p, q, delta, x1, x2;
//	printf("请分别输入一元二次方程的二次项系数、一次项系数及常数项：\n");
//	scanf("%lf %lf %lf", &a, &b, &c);
//	delta = b * b - 4 * a * c;
//	p = -b / (2 * a);
//	q = sqrt(delta) / (2 * a);
//	x1 = p - q;
//	x2 = p + q;
//	if (delta < 0)
//	{
//		printf("该方程无实数根\n");
//	}
//	else if (fabs(delta)  < 0.0001)
//	{
//		printf("该方程有两个相等的实数根：\n");
//		printf("%lf %lf\n", x1, x2);
//	}
//	else
//	{
//		printf("该方程有两个不等的实数根：\n");
//		printf("%lf %lf\n", x1, x2);
//	}
//
//	return 0;
//}


double x1, x2, p, q;
int integer_judge(double x)//判断是否是整数, 飞跃的函数啊，有了它，配合指针，可以将兼容的浮点数必要时化为简洁的整形
{
	x = fabs(x);
	while (x >= 1) x--;
	if (x == 0)return 1;//期末考的启示：第一个返回return！（条件满足的return）
	return 0;
}
void delta1()
{
	if (integer_judge(x1) && integer_judge(x2))
		printf("x1=%d,x2=%d", (int)x1, (int)x2);
	else printf("x1=%10.7f,x2=%10.7f", x1, x2);
}
void delta2()
{
	if (integer_judge(x1))
		printf("x1=x2=%d", (int)x1);
	else printf("x1=x2=%10.7f", x1);
}
void delta3()
{
	if (integer_judge(p) && integer_judge(q))
		printf("x1=%d+%di,x2=%d+%di", (int)p, -1 * (int)q, (int)p, (int)q);
	else printf("x1=%10.7f%10.7fi,x2=%10.7f+%10.7fi", p, -1 * q, p, q);
}

int main()
{
	void delta1();
	void delta2();
	void delta3();
	double a, b, c, delta;
	printf("please enter a,b,c:\n");
	scanf("%lf%lf%lf", &a, &b, &c);//是真没想到，double用%d居然就完全输入错误了！！！！！！
	delta = b * b - 4 * a * c;
	p = -1 * b / (2 * a); q = sqrt(fabs(delta)) / (2 * a);
	x1 = p - q; x2 = p + q;
	if (integer_judge(a) && integer_judge(b) && integer_judge(c))
		printf("%dx^2+%dx+%d=0\n", (int)a, (int)b, (int)c);
	if (delta > 0)delta1();
	else if (delta == 0)delta2();
	else delta3();
	return 0;
}

//int main()//果然不行么
//{
//	printf("%f", 2.1 % 2);
//	return 0;
//}
