#define _CRT_SECURE_NO_WARNINGS 1
#define MALLOC_CHECK(ptr)\
if(ptr==NULL)\
{perror("Memory allocation failed"); exit(1);}
#include <stdio.h>
#include <stdlib.h>
#define M 8
#define N 8
#define MaxSize M*N
typedef struct
{
	int i;
	int j;
	int d;
}Box;
typedef struct
{
	Box data[MaxSize];
	int top;
}StType;

void InitStack(StType * &s)
{
	s = (StType*)malloc(sizeof(StType)); MALLOC_CHECK(s);
	s->top = -1;
}

void DestroyStack(StType * &s)
{
	free(s);
}

bool StackEmpty(StType * s)
{
	return (s->top == -1);
}

bool Push(StType * s, Box e)
{
	if (s->top == MaxSize - 1)
		return false;
	s->top++;
	s->data[s->top] = e;
	return true;
}

bool Pop(StType * s, Box & e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	s->top--;
	return true;
}

bool GetTop(StType * s, Box & e)
{
	if (s->top == -1)
		return false;
	e = s->data[s->top];
	return true;
}



int mg[M + 2][N + 2] =
{ {1,1,1,1,1,1,1,1,1,1},{1,0,0,1,0,0,0,1,0,1},{1,0,0,1,0,0,0,1,0,1},{1,0,0,0,0,1,1,0,0,1}, {1,0,1,1,1,0,0,0,0,1},{1,0,0,0,1,0,0,0,0,1},{1,0,1,0,0,0,1,0,0,1},
  {1,0,1,1,1,0,1,1,0,1},{1,1,0,0,0,0,0,0,0,1},{1,1,1,1,1,1,1,1,1,1} };


bool mgpath(int xi, int yi, int xe, int ye)
{
	int i, j, i1, j1, di;
	bool find;
	Box e;
	StType* st;
	InitStack(st);
	e.i = xi; e.j = yi; e.d = -1;
	Push(st, e);
	mg[xi][yi] = -1;
	while (!StackEmpty(st))
	{
		GetTop(st, e);
		i = e.i; j = e.j; di = e.d;
		if (i == xe && j == ye)
		{
			printf("找到一条路径：\n");
			while (!StackEmpty(st))
			{
				Pop(st, e);
				switch (e.d)
				{
				case 0:mg[e.i][e.j] = 65; break;//A
				case 1:mg[e.i][e.j] = 62; break;//>
				case 2:mg[e.i][e.j] = 118; break;//v
				case 3:mg[e.i][e.j] = 60; break;//<
				}
			}
			printf("\n");
			for (int m = 0; m < M + 2; m++)
			{
				for (int n = 0; n < N + 2; n++)
				{
					if (mg[m][n] > 1)
						printf("\40%c\40", (char)mg[m][n]);//\40是空格 ascⅡ
					else if (mg[m][n] == -1)
						printf("\40\104\40");//\104是D
					else if (mg[m][n] == 0)
						printf("\40\40\40");//没用到的方格变空
					else
						printf("\40\57\40");//1变成\,更像墙壁
				}
				printf("\n");
			}
			DestroyStack(st);
			return true;
		}
		find = false;
		while (di < 4 && find != true)
		{
			di++;
			switch (di)
			{
			case 0:i1 = i - 1; j1 = j; break;
			case 1:i1 = i; j1 = j + 1; break;
			case 2:i1 = i + 1; j1 = j; break;
			case 3:i1 = i; j1 = j - 1; break;
			}
			if (mg[i1][j1] == 0)
				find = true;
		}
		if (find == true)
		{
			st->data[st->top].d = di;
			e.i = i1;
			e.j = j1;
			e.d = -1;
			Push(st, e);
			mg[i1][j1] = -1;//
		}
		else
		{
			Pop(st, e);
			mg[e.i][e.j] = 0;
		}
	}
	DestroyStack(st);
	return false;
}



int main()
{
	int xi, yi, xe, ye;
	bool m;
	printf("请分别输入入口与出口的坐标：\n");
	printf("xi:"); scanf("%d", &xi);
	printf("yi:"); scanf("%d", &yi);
	printf("xe:"); scanf("%d", &xe);
	printf("ye:"); scanf("%d", &ye);
	m = mgpath(xi, yi, xe, ye);
	printf("\n%d", mg[8][8]);
	return 0;
}