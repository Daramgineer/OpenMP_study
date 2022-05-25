#include <stdio.h>
#include <omp.h>
#include <math.h>
#define N  80

int main()
{
	omp_set_num_threads(5);
	int i, t_id, a[N];
#pragma omp parallel for private(i) schedule(static) //80�� �۾����� 5���� thread�� �����ϰ� �й��� static
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
#pragma omp parallel for private(i) schedule(dynamic, 40) //80�� �۾����� 40���� ������ thread�� �й�, 40�� ��� 0/1 thread�� �����.
	for (i = 0; i < N; i++)
	{
		a[i] = i;
		printf("a[%d] = %d, %d\n", a[i], i, omp_get_thread_num());
	}
}*/