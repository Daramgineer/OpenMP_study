#include <stdio.h>
#include <omp.h>
#include <math.h>
#define N  80

int main()
{
	omp_set_num_threads(5);
	int i, t_id, a[N];
#pragma omp parallel for private(i) schedule(static) //80의 작업량을 5개의 thread에 균일하게 분배함 static
	for (i = 0; i < N; i++)
	{
		a[i] = i;
		printf("a[%d] = %d, %d\n", a[i], i, omp_get_thread_num());
	}
}

/*int main()
{
	omp_set_num_threads(5);
	int i, t_id, a[N];
#pragma omp parallel for private(i) schedule(dynamic, 40) //80의 작업량을 40개로 나누어 thread에 분배, 40의 경우 0/1 thread만 사용함.
	for (i = 0; i < N; i++)
	{
		a[i] = i;
		printf("a[%d] = %d, %d\n", a[i], i, omp_get_thread_num());
	}
}*/