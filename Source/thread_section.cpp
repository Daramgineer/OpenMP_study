#include <stdio.h>
#include <omp.h>
#include <math.h>

void section()
{
	int i, a[10], b[20];

#pragma omp parallel private(i)
	{
#pragma omp sections //thread 하나에 작업을 할당함
		{
#pragma omp section //thread 1개
			for (i = 0; i < 10; i++)
				a[i] = i * 10 + 5;
#pragma omp section //다른 thread 1개, 할당 안된 thread는 동작x
			for (i = 0; i < 20; i++)
				b[i] = i * 5 + 10;
		}
	}

	for (i = 0; i < 10; i++)
		printf("%d  ", a[i]);
	printf("\n");
	for (i = 0; i < 20; i++)
		printf("%d  ", b[i]);
	printf("\n");
}

int main()
{
	section();
}